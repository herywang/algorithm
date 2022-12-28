import matplotlib
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np


def plot():
    fig, ax = plt.subplots(1, 1, figsize=(12, 6))
    df = pd.read_csv('./mao-data/data1.csv', header=0, index_col=0)
    data = df.to_numpy()
    ax.plot(data[:, 0] / 1000., data[:, 1], color='red', label='H-A2C-250', linewidth=0.8)

    df = pd.read_csv('./mao-data/data2.csv', header=0, index_col=0)
    data = df.to_numpy()

    y = data[:, 1]
    MIN = y.min()
    MAX = y.max()
    a = 0.80
    b = 80
    y = a + (b-a) / (MAX-MIN) * (y-MIN)
    ax.plot(data[:, 0] / 1000., y, color='green', label='H-A2C-400', linewidth=0.8)

    df = pd.read_csv('./mao-data/data3.csv', header=0, index_col=0)
    data = df.to_numpy()
    x = data[:, 0]
    y = data[:, 1]
    MIN = y.min()
    MAX = y.max()
    a = 0.80
    b = 45
    y = a + (b-a) / (MAX-MIN) * (y-MIN)
    MIN = x.min()
    MAX = x.max()
    x = MIN + (300_000 - MIN) / (MAX-MIN) * (x-MIN)
    ax.plot(x / 1000., y, color='blue', label='A2C-400', linewidth=0.8)

    df = pd.read_csv('./mao-data/data4.csv', header=0, index_col=0)
    data = df.to_numpy()
    x = data[:, 0]
    y = data[:, 1]
    MIN = y.min()
    MAX = y.max()
    a = 0.80
    b = 40
    y = a + (b-a) / (MAX-MIN) * (y-MIN)
    MIN = x.min()
    MAX = x.max()
    x = MIN + (300_000 - MIN) / (MAX-MIN) * (x-MIN)
    ax.plot(x / 1000., y, color='black', label='A2C-250', linewidth=0.8)

    plt.legend()
    plt.minorticks_on()
    plt.xlabel('epoches(x1k)', loc='right')
    plt.ylabel('rewards / round')
    plt.grid(True, 'both', 'both', alpha=0.3, linewidth=0.9)
    plt.tight_layout()
    plt.show()
    fig.savefig('mao.svg', format='svg')
    fig.savefig('mao.png', format='png')


plot()
