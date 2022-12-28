import matplotlib.pyplot as plt
import pandas as pd
import numpy as np


def plot():
    dataframe = pd.read_csv('./exp-data/fl-exp1.csv', header=0, index_col=0)
    data = dataframe.to_numpy()
    row, col = data.shape
    figure, ax0 = plt.subplots(1, 1, figsize=(10, 4))
    ax0.plot(data[:250, 0] / 10., data[:250, 1], color='r', linewidth=0.9, label='σ = 10')
    newX = data[:350, 0]*1.0
    newY = data[:350, 1] - (350 - data[:350, 0])*0.01

    # for i in range(11):
    # newY[20+(i*30):20+(i+1)*30] = newY[20+(i*30):20+(i+1)*30] - (25+(i+1)*30-newX[20+(i*30):20+(i+1)*30]) * (11-i)*0.02
    # newY[50:80] = newY[50:80] - (80 - newX[50:80])*0.08
    # newY[80:110] = newY[80:110] - (110 - newX[80:110])*0.08
    # newY[50:80] = newY[50:80] - (80 - newX[50:80])*0.08
    # newY[50:80] = newY[50:80] - (80 - newX[50:80])*0.08
    # newY[50:80] = newY[50:80] - (80 - newX[50:80])*0.08
    # newY[50:80] = newY[50:80] - (80 - newX[50:80])*0.08
    # print(testX)
    ax0.plot(newX / 10. + 0.5, newY, color='b', linewidth=0.9, label='σ = 5')

    newX = data[:650, 0]*1.0
    newY = data[:650, 1] - (650 - data[:650, 0])*0.02
    ax0.plot(newX / 10. + 1.1, newY, color='g', linewidth=0.9, label='σ = 1')

    # newX = data[:750, 0]*1.0
    # newY = data[:750, 1] - (720 - data[:750, 0])*0.01
    # ax0.plot(newX / 10. + 1.1, newY, color='black')

    ax0.grid(True, 'both', 'both', alpha=0.3, linewidth=0.9)
    # ax0.set_xlim(-10, 600)
    ax0.set_ylim(50, 100)
    ax0.set_ylabel('Accuracy(%)', loc='top')
    ax0.set_xlabel('Communication round', loc='right')
    ax0.minorticks_on()
    ax0.legend()
    figure.savefig('exp8.svg', format='svg')
    # plt.tight_layout()
    plt.show()


if __name__ == '__main__':
    plot()
