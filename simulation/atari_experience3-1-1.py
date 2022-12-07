import gym
import time
import matplotlib.pyplot as plt
import torch
import torch.nn as nn
import torch.nn.functional as F
from stable_baselines3.common.torch_layers import BaseFeaturesExtractor
from stable_baselines3.common.env_util import make_atari_env
from stable_baselines3.common.vec_env import VecFrameStack
from stable_baselines3 import A2C
from threading import Thread


class ResNetBlock(nn.Module):

    def __init__(self, in_channel, out_channel, kernel_size=3):
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
        return F.relu(x + x1)


class NormalCNN3(BaseFeaturesExtractor):

    def __init__(self, observation_space: gym.Space, features_dim: int = 64):
        super(NormalCNN3, self).__init__(observation_space, features_dim)
        n_input_channel = observation_space.shape[0]
        # print(observation_space.shape)
        self.cnn = nn.Sequential(
            nn.Conv2d(n_input_channel, 64, 3, 1),
            nn.Conv2d(64, 64, 3, 1),
            nn.MaxPool2d(2, 2),
            nn.Flatten(),
        )
        with torch.no_grad():
            # print(observation_space.sample()[None].shape)
            n_flatten = self.cnn(torch.as_tensor(observation_space.sample()[None]).float()).shape[1]
        self.linear = nn.Sequential(nn.Linear(n_flatten, features_dim), nn.ReLU())

    def forward(self, observations: torch.Tensor) -> torch.Tensor:
        return self.linear(self.cnn(observations))


class NormalCNN5(BaseFeaturesExtractor):

    def __init__(self, observation_space: gym.Space, features_dim: int = 64):
        super(NormalCNN5, self).__init__(observation_space, features_dim)
        n_input_channel = observation_space.shape[0]
        # print(observation_space.shape)
        self.cnn = nn.Sequential(
            nn.Conv2d(n_input_channel, 64, 3, 1),
            nn.BatchNorm2d(64),
            nn.ReLU(),
            nn.Conv2d(64, 64, 3, 1),
            nn.BatchNorm2d(64),
            nn.ReLU(),
            nn.MaxPool2d(2, 2),
            nn.Flatten(),
        )
        with torch.no_grad():
            # print(observation_space.sample()[None].shape)
            n_flatten = self.cnn(torch.as_tensor(observation_space.sample()[None]).float()).shape[1]
        self.linear = nn.Sequential(nn.Linear(n_flatten, features_dim), nn.ReLU())

    def forward(self, observations: torch.Tensor) -> torch.Tensor:
        return self.linear(self.cnn(observations))


class NormalCNN7(BaseFeaturesExtractor):

    def __init__(self, observation_space: gym.Space, features_dim: int = 64):
        super(NormalCNN7, self).__init__(observation_space, features_dim)
        n_input_channel = observation_space.shape[0]
        # print(observation_space.shape)
        self.cnn = nn.Sequential(
            nn.Conv2d(n_input_channel, 64, 3, 1),
            nn.BatchNorm2d(64),
            nn.ReLU(),
            nn.Conv2d(64, 64, 3, 1),
            nn.BatchNorm2d(64),
            nn.ReLU(),
            nn.Conv2d(64, 64, 3, 1),
            nn.MaxPool2d(2, 2),
            nn.BatchNorm2d(64),
            nn.ReLU(),
            nn.Conv2d(64, 64, 3, 1),
            nn.BatchNorm2d(64),
            nn.ReLU(),
            nn.Conv2d(64, 64, 3, 1),
            nn.MaxPool2d(2, 2),
            nn.Flatten(),
        )
        with torch.no_grad():
            # print(observation_space.sample()[None].shape)
            n_flatten = self.cnn(torch.as_tensor(observation_space.sample()[None]).float()).shape[1]
        self.linear = nn.Sequential(nn.Linear(n_flatten, features_dim), nn.ReLU())

    def forward(self, observations: torch.Tensor) -> torch.Tensor:
        return self.linear(self.cnn(observations))


def train_a2c(envname: str, logdir: str, policy_kwargs: dict = None):
    print("开始训练," + ' env=' + envname + ', logdir: ' + logdir)
    env = make_atari_env(envname, n_envs=3)
    env = VecFrameStack(env, n_stack=6)
    # , policy_kwargs=policy_kwargs
    if policy_kwargs is None:
        model = A2C('CnnPolicy', env, tensorboard_log=logdir, device='cuda')
    else:
        model = A2C('CnnPolicy', env, tensorboard_log=logdir, policy_kwargs=policy_kwargs, device='cuda')
    model.learn(600_000)


if __name__ == '__main__':
    # normal_m3_policy_kwargs = dict(features_extractor_class=NormalCNN3, features_extractor_kwargs=dict(features_dim=64))
    # normal_m3 = Thread(target=train_a2c, args=('ALE/Breakout-v5','./Breakout', normal_m3_policy_kwargs))
    # normal_m3.start()
    # time.sleep(5)
    train_a2c('ALE/Breakout-v5', './Breakout', None)
    # normal_m5 = Thread(target=train_a2c, args=('ALE/Breakout-v5','./Breakout', normal_m5_policy_kwargs))
    # normal_m5.start()
    # time.sleep(5)

    # normal_m7_policy_kwargs = dict(features_extractor_class=NormalCNN7, features_extractor_kwargs=dict(features_dim=64))
    # normal_m7 = Thread(target=train_a2c, args=('ALE/Breakout-v5','./Breakout', normal_m7_policy_kwargs))
    # normal_m7.start()
    # time.sleep(5)

    # normal_m3.join()
    # normal_m5.join()
    # normal_m7.join()

# plot_atari_image()
