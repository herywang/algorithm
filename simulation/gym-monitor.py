#!/Users/wangheng/app/anaconda3/envs/gym/bin/python
import time

import gym
import torch
import matplotlib.pyplot as plt
import random
import torch.nn as nn
import cv2
import numpy as np
from torch.utils.tensorboard import SummaryWriter

# LunarLander离散action space环境
env = gym.make('LunarLander-v2', render_mode="rgb_array")
np.random.seed(0)


class DQN(nn.Module):
    def __init__(self, action_space, state_space) -> None:
        super(DQN, self).__init__()
        self.action_space = action_space
        self.state_space = state_space

        self.model = nn.Sequential([
            nn.Linear(self.state_space, 100),
            nn.ReLU(),
            nn.Linear(100, 100),
            nn.ReLU(),
            nn.Linear(100, self.action_space),
            nn.Softmax(-1)
        ])

    def forward(self, x):
        return self.model(x)


class Agent:
    def __init__(self):
        self.memory = []
        self.epsilon = 0.2  # 随机度
        self.memory_counter = 0
        self.memory_max_size = 1000
        self.batch_size = 128

        self.eval_net = DQN(env.action_space.shape[0], env.observation_space.shape[0])
        self.target_net = DQN(env.action_space.shape[0], env.observation_space.shape[0])
        self.opt = torch.optim.Adam(self.eval_net.parameters(), lr=0.001)
        self.target_net.load_state_dict(self.eval_net.state_dict())

    def learn(self):
        if self.memory_counter > self.memory_max_size:
            sample_index = np.random.choice(self.memory_max_size, self.batch_size, replace=False)
        else:
            sample_index = np.random.choice(self.memory_counter, size=self.batch_size)

        batch_memory = np.array(self.memory, dtype=object)[sample_index]

    def choose_action(self, state, is_test=False):
        '''
        :param state: 当前状态
        :param is_test:
        :return:
        '''
        np.random.randint(0, env.action_space.n)
        pass

    def play(self):
        log_writer = SummaryWriter('./dqn-writer')
        start_learn_after_n_steps = 100
        epoches = 3000
        for _ in range(epoches):
            observation = env.reset()
            done = False
            sum_reward = 0.
            while not done:
                env.render()
                action = self.choose_action(observation)


if __name__ == '__main__':
    print(env.action_space)
    print(env.action_space.shape)
    print(env.action_space.sample())
    print(env.observation_space)
    # plt.imshow(env.render())
    cv2.imshow("image", env.render())
    cv2.waitKey(0)
    # plt.show()
    time.sleep(5)
