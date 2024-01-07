#!/home/wufan/hard_disk/anaconda3/bin/python
# 第三章实验
import torch
import torch.nn as nn
from torch.optim import Adam
import torch.nn.functional as F
from torchvision.datasets import CIFAR10
import torchvision.transforms as tt
from torch.utils.data.dataloader import DataLoader
from averagemeter import AverageMeter
from torch.utils.tensorboard.writer import SummaryWriter
import time

BATCH_SIZE = 100
num_works = 8
EPOCHES = 100
DEVICE = torch.device("cuda:0") if torch.cuda.is_available() else torch.device('cpu')


def accuracy(predicted: torch.Tensor, actual: torch.Tensor, topk=(1,)):
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


class ResNetBlock(nn.Module):
    def __init__(self, in_channel, out_channel, kernel_size):
        super(ResNetBlock, self).__init__()
        self.conv1 = nn.Conv2d(in_channel, out_channel, kernel_size, 1, 1)
        self.batch_norm1 = nn.BatchNorm2d(out_channel)
        self.conv2 = nn.Conv2d(out_channel, out_channel, kernel_size, 1, 1)
        self.batch_norm2 = nn.BatchNorm2d(out_channel)

    def forward(self, x):
        x1 = self.conv1(x)
        x1 = F.relu(self.batch_norm1(x1))
        x1 = self.conv2(x1)
        x1 = self.batch_norm2(x1)
        return F.relu(x+x1)


class NormalBlock(nn.Module):
    def __init__(self, in_channel, out_channel, kernel_size):
        super(NormalBlock, self).__init__()
        self.conv1 = nn.Conv2d(in_channel, out_channel, kernel_size, 1, 1)
        self.batch_norm1 = nn.BatchNorm2d(out_channel)
        self.conv2 = nn.Conv2d(out_channel, out_channel, kernel_size, 1, 1)
        self.batch_norm2 = nn.BatchNorm2d(out_channel)

    def forward(self, x):
        x = self.conv1(x)
        x = F.relu(self.batch_norm1(x))
        x = self.conv2(x)
        x = F.relu(self.batch_norm2(x))
        return x


class DepthWiseBlock(nn.Module):
    def __init__(self, in_channel, out_channel, kernel_size):
        super(DepthWiseBlock, self).__init__()
        self.conv1 = nn.Conv2d(in_channel, in_channel, kernel_size, 1, 1, groups=in_channel)
        self.batch_norm1 = nn.BatchNorm2d(in_channel)
        self.conv2 = nn.Conv2d(in_channel, out_channel, 1, 1, 1)
        self.batch_norm2 = nn.BatchNorm2d(out_channel)

    def forward(self, x):
        x = self.conv1(x)
        x = F.relu(self.batch_norm1(x))
        x = self.conv2(x)
        x = F.relu(self.batch_norm2(x))


if __name__ == '__main__':

    mean_std = ((0.5074, 0.4867, 0.4411), (0.2011, 0.1987, 0.2025))
    train_transform = tt.Compose([
        tt.RandomHorizontalFlip(),  # 0.5的概率对图片进行水平翻转
        # 最急剪裁，添加噪音，防止模型过拟合
        tt.RandomCrop(32, padding=4, padding_mode='reflect'),
        tt.ToTensor(),
        tt.Normalize(*mean_std)  # 使用ImageNet的均值方差来进行正则化
    ])

    test_transform = tt.Compose([tt.ToTensor(), tt.Normalize(*mean_std)])
    train_dataset = CIFAR10(root='./cifar10', download=False, transform=train_transform)
    test_dataset = CIFAR10(root='./cifar10', download=False, train=False, transform=test_transform)

    train_dataloader = DataLoader(train_dataset, BATCH_SIZE, num_workers=num_works, shuffle=True, pin_memory=True)
    test_dataloader = DataLoader(test_dataset, BATCH_SIZE, num_workers=num_works, pin_memory=True)

    # input: (3,32,32)
    resnet5 = nn.Sequential(
        nn.Conv2d(3, 64, 3, 1, 1),  # (64,32,32)
        nn.MaxPool2d(2, 2),  # (64,16,16)
        ResNetBlock(64, 64, 3),
        nn.MaxPool2d(2, 2),  # (64,8,8)
        ResNetBlock(64, 64, 3),
        nn.MaxPool2d(2, 2),  # (64,4,4)
        ResNetBlock(64, 64, 3),
        nn.MaxPool2d(2, 2),  # (64,2,2)
        ResNetBlock(64, 64, 3),
        ResNetBlock(64, 64, 3),
        nn.Flatten(),
        nn.Linear(256, 128),
        nn.Linear(128, 10),
        nn.Softmax(1)
    ).to(DEVICE)

    resnet10 = nn.Sequential(
        nn.Conv2d(3, 64, 3, 1, 1),  # (64,32,32)
        nn.MaxPool2d(2, 2),  # (64,16,16)
        ResNetBlock(64, 64, 3),
        ResNetBlock(64, 64, 3),
        ResNetBlock(64, 64, 3),
        ResNetBlock(64, 64, 3),
        ResNetBlock(64, 64, 3),
        ResNetBlock(64, 64, 3),
        nn.MaxPool2d(2, 2),  # (64,8,8)
        ResNetBlock(64, 64, 3),
        nn.MaxPool2d(2, 2),  # (64,4,4)
        ResNetBlock(64, 64, 3),
        ResNetBlock(64, 64, 3),
        nn.MaxPool2d(2, 2),  # (64,2,2)
        ResNetBlock(64, 64, 3),
        nn.Flatten(),
        nn.Linear(256, 128),
        nn.Linear(128, 10),
        nn.Softmax(1)
    )

    writer = SummaryWriter('./resnet5-logs', flush_secs=10)
    loss_function = nn.CrossEntropyLoss()
    optimizer = Adam(resnet5.parameters())
    resnet5.train()

    for i in range(EPOCHES):
        lossMeter = AverageMeter()
        top1Meter = AverageMeter()
        top5Meter = AverageMeter()
        for _i, (_input, target) in enumerate(train_dataloader):
            x = torch.autograd.Variable(_input).to(DEVICE)
            y = torch.autograd.Variable(target).to(DEVICE)
            print(y.size())
            start = time.time()
            predict = resnet10(x)
            end = time.time()
            print('forward: ', end-start)
            lossValue = loss_function(predict, y)
            # calculating precision 1 and precision 5
            prec1, prec5 = accuracy(predict, y, (1, 5))
            lossMeter.update(lossValue)
            top1Meter.update(prec1)
            top5Meter.update(prec5)
            start = time.time()
            optimizer.zero_grad()
            lossValue.backward()
            optimizer.step()
            end = time.time()
            print('backward: ', end-start)
            break
        break
        writer.add_scalar('loss/train', lossMeter.avg, global_step=i)
        writer.add_scalar('acc-top1/train', top1Meter.avg, global_step=i)
        writer.add_scalar('acc-top5/train', top5Meter.avg, global_step=i)

        print("Epoch {}/{}, loss:{:.4f}, top1 acc:{:.4f}, top5-acc:{:.4f}".format(i, EPOCHES, lossMeter.avg, top1Meter.avg, top5Meter.avg))

        # Evalueating model
        if i % 10 == 0:
            top1Meter.reset()
            with torch.no_grad():
                for _i, (_input, target) in enumerate(test_dataloader):
                    x = torch.autograd.Variable(_input).to(DEVICE)
                    y = torch.autograd.Variable(target).to(DEVICE)
                    predict = resnet5(x)
                    prec1 = accuracy(predict, y, (1,))[0]
                    top1Meter.update(prec1)

                writer.add_scalar('acc-top1/test', top1Meter.avg, global_step=i)
            writer.flush()

    writer.close()

    # normal_net = NormalBlock(64, 64, 3).to(DEVICE)
    # depthwise_net = DepthWiseBlock(64, 64, 3).to(DEVICE)

    # x = torch.randn(1000, 64, 32, 32).to(DEVICE)
    # start = time.time()
    # y = resnet5(x)
    # end = time.time()
    # print("resnet: ", end-start)

    # start = time.time()
    # y = normal_net(x)
    # end = time.time()
    # print("normal: ", end-start)

    # start = time.time()
    # y = depthwise_net(x)
    # end = time.time()
    # print("depth-wise: ", end-start)
