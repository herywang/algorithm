import gym
from stable_baselines3 import A2C, DQN, PPO, DDPG
from stable_baselines3.common.env_util import make_atari_env
from threading import Thread
import time

# env = gym.make('LunarLander-v2')
env = make_atari_env('ALE/Enduro-v5', n_envs=3)
# model = A2C('CnnPolicy', env, tensorboard_log='amao')
model = DQN('CnnPolicy', env, tensorboard_log='amao')
model.learn(300_000)


def train1():
    model1 = A2C('MlpPolicy', env, tensorboard_log='amao')
    model1.learn(120_000)


def train2():
    model2 = DQN('MlpPolicy', env, tensorboard_log='amao', seed=1, target_update_interval=10000)
    model2.learn(120_000)


def train3():
    model3 = PPO('MlpPolicy', env, tensorboard_log='amao')
    model3.learn(120_000)


def train4():
    model4 = DQN('MlpPolicy', env, tensorboard_log='amao', seed=2)
    model4.learn(120_000)


# thread1 = Thread(target=train1)
# thread2 = Thread(target=train2)
# thread3 = Thread(target=train3)
# thread4 = Thread(target=train4)

# thread1.start()
# time.sleep(1)
# thread2.start()
# time.sleep(1)
# thread3.start()
# time.sleep(1)
# thread4.start()
# time.sleep(1)

# thread1.join()
# thread2.join()
# thread3.join()
# thread4.join()
