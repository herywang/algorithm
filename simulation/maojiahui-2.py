import gym
from stable_baselines3 import A2C, DQN, PPO, DDPG
from stable_baselines3.common.env_util import make_atari_env
from threading import Thread
import time

# env = gym.make('LunarLander-v2')
env = make_atari_env('ALE/Enduro-v5', n_envs=3)
# model = A2C('CnnPolicy', env, tensorboard_log='amao')
# model = DQN('CnnPolicy', env, tensorboard_log='amao')
model = PPO('CnnPolicy', env, tensorboard_log='amao')
model.learn(300_000)

