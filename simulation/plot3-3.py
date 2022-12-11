import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from numpy import ma
from matplotlib import scale as mscale
from matplotlib import transforms as mtransforms
from matplotlib.ticker import FixedLocator, FuncFormatter


densenet = 'm3--'
pyramid = 'kd-'
resnet = 'cp--'
depthwise = 'g.-'
normalnet = 'r^--'


def plot1():
    marker = ['*', 'h', '^', 's', 'o', 'P']
    color = ['green', 'm', 'black', 'c', 'r', 'b']
    labels = ['DepthWise', 'DenseNet', 'Pyramid', 'ResNet', 'Normal', 'OursModel']
    dataframe = pd.read_csv('./exp-data/experience3-3.csv', header=0, index_col=0)
    data = dataframe.to_numpy()
    row, col = data.shape

    fig, axes = plt.subplots(1, 4, figsize=(18, 4))
    axes[0].set_ylim(90.2, 95.0)
    axes[0].minorticks_on()
    axes[0].set_ylabel('accuracy(%)', loc='top')
    x = np.linspace(1, 3, 3)
    for i in range(col):
        axes[0].scatter(x, data[:, i], marker=marker[i], color=color[i], label=labels[i])

    axes[0].legend()
    axes[0].set_title('CIFAR-100 Model Accuracy')
    axes[0].set_xticks(x, ['m=5', 'm=10', 'm=15'])
    axes[0].grid(True, 'both', 'both', alpha=0.3, linestyle='-.')
    # axes[0].set_yscale('function',)
    # 五种经典网络结构在不同硬件计算资源上推理计算时延
    labels = ['Intel i5 4Core\n2.5GHz', 'Intel i5 1Core\n2.0GHz', 'GTX 960m', 'Cortex Arm\nV7 1.5GHhz']
    x = np.arange(len(labels))
    width = 0.08

    datam5 = np.array([
        # 'Intel i5 \n 4Core'
        [1, 1.153],  # Pyramid
        [1, 1.068],  # DenseNet
        [1, 0.801],  # ResNet
        [1, 0.728],  # Normal
        [1, 0.313],  # Depthwise
        # Intel i5 1 Core
        [2, 1.771],  # Pyramid
        [2, 1.868],  # DenseNet
        [2, 1.501],  # ResNet
        [2, 1.428],  # Normal
        [2, 0.602],  # Depthwise
        # GTX 960m
        [3, 0.701],  # Pyramid
        [3, 0.621],  # DenseNet
        [3, 0.722],  # ResNet
        [3, 0.714],  # Normal
        [3, 0.402],  # Depthwise
        # Cortex A72
        [4, 2.053],  # Pyramid
        [4, 1.968],  # DenseNet
        [4, 1.501],  # ResNet
        [4, 1.228],  # Normal
        [4, 0.702],  # Depthwise
    ])
    datam10 = np.array([
        # 'Intel i5 \n 4Core'
        [1, 1.453],  # Pyramid
        [1, 1.368],  # DenseNet
        [1, 1.201],  # ResNet
        [1, 1.128],  # Normal
        [1, 0.607],  # Depthwise
        # Intel i5 1 Core
        [2, 2.171],  # Pyramid
        [2, 2.028],  # DenseNet
        [2, 1.901],  # ResNet
        [2, 1.528],  # Normal
        [2, 0.741],  # Depthwise
        # GTX 960m
        [3, 1.104],  # Pyramid
        [3, 0.911],  # DenseNet
        [3, 0.892],  # ResNet
        [3, 0.874],  # Normal
        [3, 0.542],  # Depthwise
        # Cortex A72
        [4, 2.453],  # Pyramid
        [4, 2.268],  # DenseNet
        [4, 1.801],  # ResNet
        [4, 1.528],  # Normal
        [4, 0.742],  # Depthwise
    ])
    datam15 = np.array([
        # 'Intel i5 \n 4Core'
        [1, 1.653],  # Pyramid
        [1, 1.568],  # DenseNet
        [1, 1.401],  # ResNet
        [1, 1.328],  # Normal
        [1, 0.711],  # Depthwise
        # Intel i5 1 Core
        [2, 2.371],  # Pyramid
        [2, 2.428],  # DenseNet
        [2, 2.301],  # ResNet
        [2, 1.928],  # Normal
        [2, 0.741],  # Depthwise
        # GTX 960m
        [3, 1.104],  # Pyramid
        [3, 0.911],  # DenseNet
        [3, 0.892],  # ResNet
        [3, 0.874],  # Normal
        [3, 0.542],  # Depthwise
        # Cortex A72
        [4, 3.453],  # Pyramid
        [4, 3.268],  # DenseNet
        [4, 2.501],  # ResNet
        [4, 2.428],  # Normal
        [4, 0.942],  # Depthwise
    ])
    pyramid = datam5[0:20:5]
    densenet = datam5[1:20:5]
    resnet = datam5[2:20:5]
    normal = datam5[3:20:5]
    depthwise = datam5[4:20:5]
    # plt.title('m=5')  # 设置标题

    # fig, (ax0, ax1, ax2) = plt.subplots(nrows=1, ncols=3, sharex=True, figsize=(13, 4))
    ax0 = axes[1]
    ax1 = axes[2]
    ax2 = axes[3]
    ax0.set_title('Latency(m=5)')
    ax1.set_title('Latency(m=10)')
    ax2.set_title('Latency(m=15)')
    ax0.minorticks_on()  # 显示小刻度
    ax1.minorticks_on()  # 显示小刻度
    ax2.minorticks_on()  # 显示小刻度
    ax0.set_ylabel('latency(s)', loc='top')

    ax0.grid(True, 'both', 'y', alpha=0.3, linestyle='-.')
    rect1 = ax0.bar(x - width / 2 * 4, pyramid[:, 1], width, label='Pyramid', color='black')
    rect2 = ax0.bar(x - width / 2 * 2, densenet[:, 1], width, label='DenseNet', color='m')
    rect3 = ax0.bar(x, resnet[:, 1], width, label='ResNet', color='c')
    rect4 = ax0.bar(x + width / 2 * 2, normal[:, 1], width, label='Normal', color='r')
    rect5 = ax0.bar(x + width / 2 * 4, depthwise[:, 1], width, label='DepthWise', color='g')
    ax0.set_ylim(0.0, 3.5)
    ax0.scatter(x + width / 2 * 7, [0.36, 0.62, 0.37, 0.74], color=color[5], marker=marker[2], label='OurModel')

    pyramid = datam10[0:20:5]
    densenet = datam10[1:20:5]
    resnet = datam10[2:20:5]
    normal = datam10[3:20:5]
    depthwise = datam10[4:20:5]

    rect1 = ax1.bar(x - width / 2 * 4, pyramid[:, 1], width, label='Pyramid', color='black')
    rect2 = ax1.bar(x - width / 2 * 2, densenet[:, 1], width, label='DenseNet', color='m')
    rect3 = ax1.bar(x, resnet[:, 1], width, label='ResNet', color='c', alpha=0.7)
    rect4 = ax1.bar(x + width / 2 * 2, normal[:, 1], width, label='Normal', color='r')
    rect5 = ax1.bar(x + width / 2 * 4, depthwise[:, 1], width, label='DepthWise', color='g')
    ax1.set_ylim(0.0, 3.5)
    ax1.scatter(x + width / 2 * 7, [0.70, 0.83, 0.48, 0.94], color=color[5], marker=marker[2], label='OurModel')
    ax1.grid(True, 'both', 'y', alpha=0.3, linestyle='-.')

    pyramid = datam15[0:20:5]
    densenet = datam15[1:20:5]
    resnet = datam15[2:20:5]
    normal = datam15[3:20:5]
    depthwise = datam15[4:20:5]

    rect1 = ax2.bar(x - width / 2 * 4, pyramid[:, 1], width, label='Pyramid', color='black')
    rect2 = ax2.bar(x - width / 2 * 2, densenet[:, 1], width, label='DenseNet', color='m')
    rect3 = ax2.bar(x, resnet[:, 1], width, label='ResNet', color='c')
    rect4 = ax2.bar(x + width / 2 * 2, normal[:, 1], width, label='Normal', color='r')
    rect5 = ax2.bar(x + width / 2 * 4, depthwise[:, 1], width, label='DepthWise', color='g')
    ax2.set_ylim(0.0, 3.5)
    ax2.grid(True, 'both', 'y', alpha=0.3, linestyle='-.')
    ax2.scatter(x + width / 2 * 7, [0.83, 1.01, 0.51, 1.29], color=color[5], marker=marker[2], label='OurModel')

    ax0.set_xticks(x, labels)
    ax1.set_xticks(x, labels)
    ax2.set_xticks(x, labels)
    ax0.legend()

    plt.tight_layout()
    fig.savefig('exp7.svg', format='svg')
    plt.show()


plot1()
