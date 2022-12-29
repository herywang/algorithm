import time

import torch
import torch.nn as nn
import torch.nn.functional as F
import torchvision
from torch.utils.tensorboard import SummaryWriter
import numpy
from torchvision.datasets import CIFAR10
from torchvision.datasets import VisionDataset
from torchvision.transforms import ToTensor
from torchvision.utils import make_grid
from torch.utils.data.dataloader import DataLoader
from torch.utils.data import random_split
import torchvision.transforms as tt
import os
import matplotlib.pyplot as plt

train_transform = None
test_transform = None
train_dataset: VisionDataset = None
test_dataset: VisionDataset = None
device = None
train_dataloader: DataLoader = None
test_dataloader: DataLoader = None

model_name = 'normalnet5-1229'

train_writer = SummaryWriter(model_name + '/train')
evaluate_writer = SummaryWriter(model_name + '/test')
best_acc_top1 = 0.1


def get_device():
    if torch.cuda.is_available():
        return torch.device('cuda')
    return torch.device('cpu')


def to_device(data: torch.Tensor, device):
    if isinstance(data, (list, tuple)):
        return [to_device(x, device) for x in data]
    return data.to(device, non_blocking=True)


def accuracy(predicted: torch.Tensor, actual: torch.Tensor, topk=(1, )):
    maxk = max(topk)
    batch_size = actual.size(0)
    _, pred = predicted.topk(maxk, 1, True, True)
    pred = pred.t()
    correct = pred.eq(actual.view(1, -1).expand_as(pred))

    res = []
    for k in topk:
        correct_k = correct[:k].contiguous().view(-1).float().sum(0)
        res.append(correct_k.mul_(100.0 / batch_size))
    return res


def conv_bn(in_channel, out_channel, stride):
    return nn.Sequential(
        nn.Conv2d(in_channel, out_channel, 3, stride, 1, bias=False),
        nn.BatchNorm2d(out_channel),
        nn.ReLU6(inplace=True),
    )


def conv_dw(in_channel, out_channel, stride):
    return nn.Sequential(
        nn.Conv2d(in_channel, in_channel, 3, stride, 1, groups=in_channel, bias=False),
        nn.BatchNorm2d(in_channel),
        nn.ReLU6(inplace=True),
        nn.Conv2d(in_channel, out_channel, 1, 1, 0, bias=False),
        nn.BatchNorm2d(out_channel),
        nn.ReLU6(inplace=True),
    )


class AverageMeter(object):

    def __init__(self):
        self.reset()

    def reset(self):
        self.val = 0.
        self.avg = 0.
        self.sum = 0.
        self.count = 0.
        self.max = -999999.
        self.min = 0xFFFFFFF

    def update(self, val, n=1):
        self.val = val
        if val > self.max:
            self.max = val
        if val < self.min:
            self.min = val
        self.sum += val * n
        self.count += n
        self.avg = self.sum / self.count


class BaseModel(nn.Module):

    def training_step(self, batch):
        images, labels = batch
        out = self(images)
        loss = F.cross_entropy(out, labels)
        return loss

    def validation_step(self, batch):
        images, labels = batch
        out = self(images)
        loss = F.cross_entropy(out, labels)
        acc = accuracy(out, labels)
        return {'val_loss': loss.detach(), 'val_acc': acc}

    def validation_epoch_end(self, outputs):
        batch_losses = [loss['val_loss'] for loss in outputs]
        loss = torch.stack(batch_losses)
        batch_accuracy = [accuracy['val_acc'] for accuracy in outputs]
        acc = torch.stack(batch_accuracy).mean()
        return {'val_loss': loss.item(), 'val_acc': acc.item()}

    def epoch_end(self, epoch, result):
        print("Epoch [{}], last_learning_rate: {:.5f}, train_loss: {:.4f}, val_loss:{:.4f}, val_acc:{:.4f}".format(epoch, result['lrs'][-1], result['train_loss'], result['val_loss'],
                                                                                                                   result['val_acc']))


class NormalNet5(BaseModel):

    def __init__(self):
        super(NormalNet5, self).__init__()
        # input image size: (3,32,32)
        self.normal_model = nn.Sequential(
            conv_bn(3, 32, 1),  # ->(32,16,16)
            nn.MaxPool2d(2, 2),
            conv_bn(32, 64, 1),
            conv_bn(64, 128, 1),
            nn.MaxPool2d(2, 2),
            conv_bn(128, 128, 1),
            nn.MaxPool2d(2, 2),
            conv_bn(128, 128, 1),  # ->(256,8,8)
            nn.Flatten(),
        )

        with torch.no_grad():
            x = torch.randn(1, 3, 32, 32)
            print(x.shape)
            num_neuran = self.normal_model(x).view(1, -1).shape[1]

        self.fc = nn.Sequential(nn.Linear(num_neuran, 10), nn.BatchNorm1d(10), nn.Softmax(-1))

    def forward(self, x: torch.Tensor):
        x2 = self.normal_model(x)
        x2 = self.fc(x2)
        return x2


class NormalNet7(BaseModel):

    def __init__(self):
        super(NormalNet7, self).__init__()
        # input image size: (3,32,32)
        self.normal_model = nn.Sequential(
            conv_bn(3, 32, 1),  # ->(32,16,16)
            nn.MaxPool2d(2, 2),
            conv_bn(32, 64, 1),
            conv_bn(64, 128, 1),
            nn.MaxPool2d(2, 2),
            conv_bn(128, 128, 1),
            conv_bn(128, 128, 1),
            nn.MaxPool2d(2, 2),
            conv_bn(128, 64, 1),  # ->(256,8,8)
            nn.Flatten(),
        )

        with torch.no_grad():
            x = torch.randn(1, 3, 32, 32)
            print(x.shape)
            num_neuran = self.normal_model(x).view(1, -1).shape[1]

        self.fc = nn.Sequential(nn.Linear(num_neuran, 10), nn.BatchNorm1d(10), nn.Softmax())

    def forward(self, x: torch.Tensor):
        x2 = self.normal_model(x)
        x2 = self.fc(x2)
        return x2


class MobileNetV1(BaseModel):

    def __init__(self) -> None:
        super(MobileNetV1, self).__init__()

        # input image size: (3 32 32)
        self.model = nn.Sequential(
            conv_bn(3, 32, 2),  # -> (32, 16, 16)
            conv_dw(32, 64, 1),  # -> (64, 16, 16)
            nn.MaxPool2d(2, 2),
            conv_dw(64, 128, 1),  # (128, 16, 16)
            nn.MaxPool2d(2, 2),
            conv_dw(128, 128, 1),  # (128, 16, 16)
            conv_dw(128, 128, 1),  # (128, 16, 16)
            nn.MaxPool2d(2, 2),
            nn.Flatten())
        with torch.no_grad():
            x = torch.randn(1, 3, 32, 32)
            feature_num = self.model(x).shape[1]

        self.fc = nn.Sequential(nn.Linear(feature_num, 128), nn.ReLU(), nn.Linear(128, 128), nn.BatchNorm1d(128), nn.ReLU(), nn.Linear(128, 100), nn.Softmax(1))

    def forward(self, x: torch.Tensor) -> torch.Tensor:
        x1 = self.model(x)
        x1 = self.fc(x1)
        return x1


def __init_datset() -> None:
    global train_transform, test_transform, train_dataset, test_dataset
    mean_std = ((0.5074, 0.4867, 0.4411), (0.2011, 0.1987, 0.2025))
    train_transform = tt.Compose([
        tt.RandomHorizontalFlip(),  # 0.5的概率对图片进行水平翻转
        # 最急剪裁，添加噪音，防止模型过拟合
        tt.RandomCrop(32, padding=4, padding_mode='reflect'),
        tt.ToTensor(),
        tt.Normalize(*mean_std)  # 使用ImageNet的均值方差来进行正则化
    ])

    test_transform = tt.Compose([tt.ToTensor(), tt.Normalize(*mean_std)])

    strPath = "./data/"

    if not os.path.exists(strPath) or len(os.listdir(strPath)) == 0:
        if not os.path.exists(strPath):
            os.mkdir(strPath)
        print("starting download cifar-10 dataset...")
        train_dataset = CIFAR10(root=strPath, download=True, transform=train_transform)
        test_dataset = CIFAR10(root=strPath, download=True, train=False, transform=test_transform)
    else:
        print("loading exist cifar-10 dataset...")
        train_dataset = CIFAR10(root=strPath, download=False, transform=train_transform)
        test_dataset = CIFAR10(root=strPath, download=False, transform=test_transform)


def __init_dataloader() -> None:
    BATCH_SIZE = 128
    global train_dataloader, test_dataloader
    train_dataloader = DataLoader(train_dataset, BATCH_SIZE, num_workers=2, pin_memory=True, shuffle=True)
    test_dataloader = DataLoader(test_dataset, BATCH_SIZE, num_workers=2, pin_memory=True)


class ToDeviceLoader:

    def __init__(self, data: DataLoader, device) -> None:
        self.data = data
        self.device = device

    def __iter__(self):
        for batch in self.data:
            yield to_device(batch, self.device)


def evaluate_model_precision(model: nn.Module, test_data_loader: DataLoader, loss_function, step, opt: torch.optim.Optimizer):
    lossMeter = AverageMeter()
    top1Meter = AverageMeter()
    with torch.no_grad():
        for i, (_input, target) in enumerate(test_data_loader):
            x = torch.autograd.Variable(_input).to(device)
            y = torch.autograd.Variable(target).to(device)
            predict = model(x)
            lossValue = loss_function(predict, y)
            # calculating precision 1 and precision 5
            prec1 = accuracy(predict, y, (1, ))[0]
            lossMeter.update(lossValue)
            top1Meter.update(prec1)
        evaluate_writer.add_scalar('acc-top1', top1Meter.avg, global_step=step)
        evaluate_writer.add_scalar('loss', lossMeter.avg, global_step=step)
        if top1Meter.avg > best_acc_top1:
            print('save model, best top1-acc is: {0:.5f}'.format(top1Meter.avg))
            torch.save({'epoch': step, 'model_state_dict': model.state_dict(), 'optimizer_state_dict': opt.state_dict(), 'loss:': loss_function}, './' + model_name + '/model.checkpoint')


def train(net: nn.Module, lossFunction, optimizer: torch.optim.Optimizer, epoches: int):
    lossMeter = AverageMeter()
    top1Meter = AverageMeter()
    top5Meter = AverageMeter()

    for epoch in range(epoches):
        lossMeter.reset()
        top1Meter.reset()
        top5Meter.reset()
        net.train()
        for i, (_input, target) in enumerate(train_dataloader):
            x = torch.autograd.Variable(_input).to(device)
            y = torch.autograd.Variable(target).to(device)
            predict = net(x)
            lossValue = lossFunction(predict, y)
            # calculating precision 1 and precision 5
            prec1, prec5 = accuracy(predict, y, (1, 5))
            lossMeter.update(lossValue)
            top1Meter.update(prec1)
            top5Meter.update(prec5)

            optimizer.zero_grad()
            lossValue.backward()
            optimizer.step()

        train_writer.add_scalar('loss', lossMeter.avg, global_step=epoch)
        train_writer.add_scalar('acc-top1', top1Meter.avg, global_step=epoch)
        train_writer.add_scalar('acc-top1-max', top1Meter.max, global_step=epoch)
        train_writer.add_scalar('acc-top1-min', top1Meter.min, global_step=epoch)
        train_writer.add_scalar('acc-top5', top5Meter.avg, global_step=epoch)
        # evaluating model precision.
        evaluate_model_precision(net, test_dataloader, lossFunction, epoch, optimizer)
        print("epoch: ", epoch)

        if epoch % 10 == 0:
            print('Epoch: [{0}][{1}]\t'
                  'Loss {loss.val:.4f} ({loss.avg:.4f})\t'
                  'Prec@1 {top1.val:.3f} ({top1.avg:.3f})\t'
                  'Prec@5 {top5.val:.3f} ({top5.avg:.3f})'.format(epoch, epoches, loss=lossMeter, top1=top1Meter, top5=top5Meter))

    train_writer.close()
    evaluate_writer.close()


if __name__ == "__main__":

    __init_datset()
    __init_dataloader()
    epoches = 1000

    # __show_batch(train_dataloader)

    end = time.time()
    device = get_device()
    # net1 = MobileNetV1().to(device)
    net = NormalNet5().to(device)
    # net2 = NormalNet7().to(device)
    # net = MobileNetV1().to(device)
    lossFunction1 = torch.nn.CrossEntropyLoss()
    # lossFunction2 = torch.nn.CrossEntropyLoss()
    # optimizer1 = torch.optim.Adam(net1.parameters())
    optimizer2 = torch.optim.Adam(net.parameters())

    train(net, lossFunction1, optimizer2, 300)

# for image, label in train_dataset:
#     print("Image shape: ", image.shape)
#     print("Image tensor: ", image)
#     print("Label: ", label)
#     break

# 统计每个标签数据数量
# train_class_items = dict()
# for train_item in train_dataset:
#     label_index = train_item[1]
#     label = train_dataset.classes[label_index]
#     if label not in train_class_items:
#         train_class_items[label] = 1
#     else:
#         train_class_items[label] += 1

# print(train_class_items)
# print(train_dataset.classes)
