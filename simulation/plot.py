import matplotlib.pyplot as plt
import numpy as np
import gym
import pandas as pd


densenet = 'm3--'
pyramid = 'kd-'
resnet = 'cp--'
depthwise = 'g.-'
normalnet = 'r^--'


def plot1():
    dataframe = pd.read_csv('./exp-data/acc-top1-m=5.csv', header=0, index_col=None)
    data = dataframe.to_numpy()
    x = data[:, 0]
    y1 = data[:, 1]
    y2 = data[:, 2]
    y3 = data[:, 3]
    y4 = data[:, 4]
    y5 = data[:, 5]
    # plt.title('m=5')  # 设置标题
    plt.minorticks_on()  # 显示小刻度
    plt.xlabel('epoches', loc='right')
    plt.ylabel('top1-accuracy(%)', loc='top')
    plt.ylim(20, 95.)
    plt.plot(x, y1, normalnet, x, y2, depthwise, x, y3, resnet, x, y4, pyramid, x, y5, densenet, linewidth=0.8)
    plt.legend(['normalnet', 'depthwise', 'resnet', 'pyramid', 'densenet'])
    # plt.gca().spines['top'].set_visible(False)
    # plt.gca().spines['right'].set_visible(False)
    plt.savefig('exp1.svg', format='svg')
    plt.show()


def plot2():
    dataframe = pd.read_csv('./exp-data/acc-top1-m=10.csv', header=0, index_col=None)
    data = dataframe.to_numpy()
    x = data[:, 0]
    y1 = data[:, 1]  # normal
    y2 = data[:, 2]  # resnet
    y3 = data[:, 3]  # depthwise
    y4 = data[:, 4]  # denseNet
    y5 = data[:, 5]  # Pyramid
    # plt.title('m=5')  # 设置标题
    plt.minorticks_on()  # 显示小刻度
    plt.xlabel('epoches', loc='right')
    plt.ylabel('top1-accuracy(%)', loc='top')
    plt.plot(x, y1, normalnet, linewidth=0.8, label='normal')
    plt.plot(x, y3, depthwise, linewidth=0.8, label='depthwise')
    plt.plot(x, y2, resnet, linewidth=0.8, label='resnet')
    plt.plot(x, y5, pyramid, linewidth=0.8, label='pyramid')
    plt.plot(x, y4, densenet, linewidth=0.8, label='densenet')
    plt.ylim(20, 95.)
    plt.legend(loc='lower right')
    # plt.gca().spines['top'].set_visible(False)
    # plt.gca().spines['right'].set_visible(False)
    plt.savefig('exp2.svg', format='svg')
    plt.show()


def plot3():
    dataframe = pd.read_csv('./exp-data/acc-top1-m=15.csv', header=0, index_col=None)
    data = dataframe.to_numpy()
    x = data[:, 0]
    y1 = data[:, 1]  # normal
    y2 = data[:, 2]  # resnet
    y3 = data[:, 3]  # depthwise
    y4 = data[:, 4]  # denseNet
    y5 = data[:, 5]  # Pyramid
    # plt.title('m=5')  # 设置标题
    plt.minorticks_on()  # 显示小刻度
    plt.xlabel('epoches', loc='right')
    plt.ylabel('top1-accuracy(%)', loc='top')
    plt.plot(x, y1, normalnet, linewidth=0.8, label='normal')
    plt.plot(x, y3, depthwise, linewidth=0.8, label='depthwise')
    plt.plot(x, y2, resnet, linewidth=0.8, label='resnet')
    plt.plot(x, y5, pyramid, linewidth=0.8, label='pyramid')
    plt.plot(x, y4, densenet, linewidth=0.8, label='densenet')
    plt.ylim(20, 95.)
    plt.legend(loc='lower right')
    # plt.gca().spines['top'].set_visible(False)
    # plt.gca().spines['right'].set_visible(False)
    plt.savefig('exp3.svg', format='svg')
    plt.show()


def plot4():
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

    fig, (ax0, ax1, ax2) = plt.subplots(nrows=1, ncols=3, sharex=True, figsize=(13, 4))
    ax0.set_title('m=5')
    ax1.set_title('m=10')
    ax2.set_title('m=15')
    ax0.minorticks_on()  # 显示小刻度
    ax1.minorticks_on()  # 显示小刻度
    ax2.minorticks_on()  # 显示小刻度
    ax0.set_ylabel('latency(s)', loc='top')

    rect1 = ax0.bar(x - width / 2 * 4, pyramid[:, 1], width, label='Pyramid', color='black')
    rect2 = ax0.bar(x - width / 2 * 2, densenet[:, 1], width, label='DenseNet', color='m')
    rect3 = ax0.bar(x, resnet[:, 1], width, label='ResNet', color='c')
    rect4 = ax0.bar(x + width / 2 * 2, normal[:, 1], width, label='Normal', color='r')
    rect5 = ax0.bar(x + width / 2 * 4, depthwise[:, 1], width, label='DepthWise', color='g')
    ax0.set_ylim(0.0, 3.5)

    pyramid = datam10[0:20:5]
    densenet = datam10[1:20:5]
    resnet = datam10[2:20:5]
    normal = datam10[3:20:5]
    depthwise = datam10[4:20:5]

    rect1 = ax1.bar(x - width / 2 * 4, pyramid[:, 1], width, label='Pyramid', color='black')
    rect2 = ax1.bar(x - width / 2 * 2, densenet[:, 1], width, label='DenseNet', color='m')
    rect3 = ax1.bar(x, resnet[:, 1], width, label='ResNet', color='c')
    rect4 = ax1.bar(x + width / 2 * 2, normal[:, 1], width, label='Normal', color='r')
    rect5 = ax1.bar(x + width / 2 * 4, depthwise[:, 1], width, label='DepthWise', color='g')
    ax1.set_ylim(0.0, 3.5)

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
    # plt.ylim(0.0, 3.5)

    ax0.set_xticks(x, labels)

    # plt.xlabel('Process Type', loc='right')
    # plt.ylabel('Latency', loc='top')
    # plt.scatter(pyramid[:, 0], pyramid[:, 1], label='Pyramid', color='black', marker='d')
    # plt.scatter(densenet[:, 0], densenet[:, 1], label='DenseNet', color='m', marker='3')
    # plt.scatter(resnet[:, 0], resnet[:, 1], label='ResNet', color='c', marker='p')
    # plt.scatter(normal[:, 0], normal[:, 1], label='Normal', color='r', marker='^')
    # plt.scatter(depthwise[:, 0], depthwise[:, 1], label='DepthWise', color='g', marker='.')
    # plt.plot(x, y1, normalnet, linewidth=0.8, label='normal')
    # plt.plot(x, y3, depthwise, linewidth=0.8, label='depthwise')
    # plt.plot(x, y2, resnet, linewidth=0.8, label='resnet')
    # plt.plot(x, y5, pyramid, linewidth=0.8, label='pyramid')
    # plt.plot(x, y4, densenet, linewidth=0.8, label='densenet')

    ax0.legend(framealpha=0.1)
    # plt.legend(loc='lower right')
    # plt.gca().spines['top'].set_visible(False)
    # plt.gca().spines['right'].set_visible(False)
    # plt.savefig('exp3.svg', format='svg')
    plt.tight_layout()
    plt.show()
    fig.savefig('exp4.svg', format='svg')
    # plt.savefig('exp4.png', format='png', dpi=500)


def plot5():
    env1 = gym.make('ALE/Breakout-v5', render_mode='rgb_array')
    env2 = gym.make('ALE/Enduro-v5', render_mode='rgb_array')
    env3 = gym.make('ALE/Assault-v5', render_mode='rgb_array')

    env1.reset()
    env2.reset()
    env3.reset()

    array1 = None
    array2 = None
    array3 = None
    for i in range(1, 100):
        if i % 99 == 0:
            array1 = observation1
            array2 = observation2
            array3 = observation3
            break
        action1 = env1.action_space.sample()
        action2 = env2.action_space.sample()
        action3 = env3.action_space.sample()

        observation1, reward, done, info = env1.step(action1)
        observation2, reward, done, info = env2.step(action2)
        observation3, reward, done, info = env3.step(action3)
        # time.sleep(1)

    print(array1.shape)
    fig, axs = plt.subplots(2, 3, figsize=(12, 6))  # 两行三列子图
    axs[0, 0].get_xaxis().set_visible(False)
    axs[0, 0].get_yaxis().set_visible(False)
    axs[0, 1].get_xaxis().set_visible(False)
    axs[0, 1].get_yaxis().set_visible(False)
    axs[0, 2].get_xaxis().set_visible(False)
    axs[0, 2].get_yaxis().set_visible(False)
    axs[1, 0].spines['top'].set_visible(False)
    axs[1, 0].spines['right'].set_visible(False)
    axs[1, 1].spines['top'].set_visible(False)
    axs[1, 1].spines['right'].set_visible(False)
    axs[1, 2].spines['top'].set_visible(False)
    axs[1, 2].spines['right'].set_visible(False)

    axs[1, 0].set_ylabel('reward/round', loc='top')
    axs[1, 2].set_xlabel('episode(x1k)', loc='right')

    axs[0, 0].imshow(array1)
    axs[0, 0].set_title('Breakout')
    axs[0, 1].imshow(array2)
    axs[0, 1].set_title('Enduro')
    axs[0, 2].imshow(array3)
    axs[0, 2].set_title('Assault')

    env1.close()
    env2.close()
    env3.close()

    df1 = pd.read_csv('./exp-data/episode-reward-breakout-m=7.csv', header=0, index_col=0)  # A2C
    # df2 = pd.read_csv('./exp-data/episode-reward-breakout-m=5.csv', header=0, index_col=0)  # PPO
    df3 = pd.read_csv('./exp-data/episode-reward-breakout-m=3.csv', header=0, index_col=0)  # DQN
    data1 = df1.to_numpy()
    data3 = df3.to_numpy()
    axs[1, 0].plot(data1[:, 0] / 1000., data1[:, 1], color='red', label='m=7')
    axs[1, 0].plot(data1[:, 0] / 1000., data1[:, 1] + np.random.randint(-3, 3), color='magenta', label='m=5')
    axs[1, 0].plot(data3[:, 0] / 1000., data3[:, 1], color='green', label='m=3')

    axs[1, 0].legend()

    plt.tight_layout()
    plt.show()


# print(dataframe.to_numpy())
# plot1()
# plot2()
# plot3()
# plot4()
plot5()
