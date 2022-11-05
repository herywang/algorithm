#!/home/wangheng/miniconda3/bin/python
import torch
import torch.nn as nn
import torch.nn.functional as F
import torchvision
import numpy
from torchvision.datasets import CIFAR100
from torchvision.datasets import VisionDataset
from torchvision.transforms import ToTensor
from torchvision.utils import make_grid
from torch.utils.data.dataloader import DataLoader
from torch.utils.data import random_split
import torchvision.transforms as tt
import os
import matplotlib.pyplot as plt
from experiment_util import *

train_transform = None
test_transform = None
train_dataset: VisionDataset = None
test_dataset: VisionDataset = None

train_dataloader: DataLoader = None
test_dataloader: DataLoader = None


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


class MobileNetV1(nn.Module):

    def __init__(self) -> None:
        super(MobileNetV1, self).__init__()

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

        self.model = nn.Sequential()


def __init_datset() -> None:
    mean_std = ((0.5074, 0.4867, 0.4411), (0.2011, 0.1987, 0.2025))
    train_transform = tt.Compose([
        tt.RandomHorizontalFlip(),  # 0.5的概率对图片进行水平翻转
        tt.RandomCrop(32, padding=4, padding_mode='reflect'),  # 最急剪裁，添加噪音，防止模型过拟合
        tt.ToTensor(),
        tt.Normalize(*mean_std)  # 使用ImageNet的均值方差来进行正则化
    ])

    test_transform = tt.Compose([tt.ToTensor(), tt.Normalize(*mean_std)])

    global train_dataset, test_dataset
    strPath = "/home/wangheng/workspace/CLionProjects/algorithm/data/"

    if not os.path.exists(strPath) or len(os.listdir(strPath)) == 0:
        if not os.path.exists(strPath):
            os.mkdir(strPath)
        print("starting download cifar-100 dataset...")
        train_dataset = CIFAR100(root=strPath, download=True, transform=train_transform)
        test_dataset = CIFAR100(root=strPath, download=True, train=False, transform=test_transform)
    else:
        print("loading exist cifar-100 dataset...")
        train_dataset = CIFAR100(root=strPath, download=False, transform=train_transform)
        test_dataset = CIFAR100(root=strPath, download=False, transform=test_transform)


def __init_dataloader() -> None:
    BATCH_SIZE = 128
    global train_dataloader, test_dataloader
    train_dataloader = DataLoader(train_dataset, BATCH_SIZE, num_workers=4, pin_memory=True, shuffle=True)
    test_dataloader = DataLoader(test_dataset, BATCH_SIZE, num_workers=4, pin_memory=True)


def __show_batch(dl: DataLoader) -> None:
    for batch in dl:
        print("show image")
        images, labels = batch
        fig, ax = plt.subplots(figsize=(7.5, 7.5))
        ax.set_yticks([])
        ax.set_xticks([])
        ax.imshow(make_grid(images[:20], nrow=5).permute(1, 2, 0))
        plt.show()
        break


class ToDeviceLoader:

    def __init__(self, data: DataLoader, device) -> None:
        self.data = data
        self.device = device

    def __iter__(self):
        for batch in self.data:
            yield to_device(batch, self.device)


if __name__ == "__main__":

    __init_datset()

    __init_dataloader()

    # __show_batch(train_dataloader)

    print(get_device())

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
