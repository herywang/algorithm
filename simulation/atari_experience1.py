import gym
import matplotlib.pyplot as plt
import torch
import torch.nn as nn
import torch.nn.functional as F
import time
import numpy as np
from stable_baselines3 import A2C, PPO, DQN
from stable_baselines3.common.torch_layers import BaseFeaturesExtractor
from stable_baselines3.common.env_util import make_atari_env
from stable_baselines3.common.vec_env import VecFrameStack

env1 = gym.make('ALE/Breakout-v5', render_mode='rgb_array')
env2 = gym.make('ALE/Enduro-v5', render_mode='rgb_array')
env3 = gym.make('ALE/Assault-v5', render_mode='rgb_array')


class RestFeature(BaseFeaturesExtractor):
    def __init__(self, observation_space: gym.Space, features_dim: int = 64):
        super(RestFeature, self).__init__(observation_space, features_dim)
        n_input_channel = observation_space.shape[0]
        # print(observation_space.shape)
        self.cnn = nn.Sequential(
            nn.Conv2d(n_input_channel, 64, 3, 1, padding=1),
            nn.BatchNorm2d(64),
            nn.ReLU(),
            nn.Conv2d(64, 4, 3, 1, 1),
            nn.BatchNorm2d(4),
        )
        with torch.no_grad():
            # print(observation_space.sample()[None].shape)
            n_flatten = self.cnn(torch.as_tensor(observation_space.sample()[None]).float()).view(1, -1).shape[1]
        self.linear = nn.Sequential(
            nn.Linear(n_flatten, features_dim),
            nn.ReLU()
        )

    def forward(self, observations: torch.Tensor) -> torch.Tensor:
        x = torch.flatten(F.relu(self.cnn(observations)+observations), 1)
        return self.linear(x)


def plot_atari_image():
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

        observation1, reward, done, truncated, info = env1.step(action1)
        observation2, reward, done, truncated, info = env2.step(action2)
        observation3, reward, done, truncated, info = env3.step(action3)
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

    axs[1, 0].set_ylabel('reward', loc='top')
    axs[1, 2].set_xlabel('episode', loc='right')

    axs[0, 0].imshow(array1)
    axs[0, 0].set_title('Breakout')
    axs[0, 1].imshow(array2)
    axs[0, 1].set_title('Enduro')
    axs[0, 2].imshow(array3)
    axs[0, 2].set_title('Assault')

    env1.close()
    env2.close()
    env3.close()

    plt.tight_layout()
    plt.show()


def train_sac():
    policy_kwargs = dict(
        features_extractor_class=RestFeature,
        features_extractor_kwargs=dict(features_dim=64)
    )
    env = make_atari_env('ALE/Breakout-v5', n_envs=3)
    env = VecFrameStack(env, n_stack=4)
    # , policy_kwargs=policy_kwargs
    model = A2C('CnnPolicy', env, tensorboard_log='./breakoutv5', verbose=1, policy_kwargs=policy_kwargs)
    model.learn(550_000)


# plot_atari_image()
train_sac()
