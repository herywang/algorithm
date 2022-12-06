import gym
import matplotlib.pyplot as plt
import torch
import torch.nn as nn
import time
import numpy as np

env1 = gym.make('ALE/Breakout-v5', render_mode='rgb_array')
env2 = gym.make('ALE/Enduro-v5', render_mode='rgb_array')
env3 = gym.make('ALE/Assault-v5', render_mode='rgb_array')
env1.metadata['render_fps'] = 60
env2.metadata['render_fps'] = 60
env3.metadata['render_fps'] = 60
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

axs[0, 0].imshow(array1)

axs[0, 0].set_title('Breakout')
axs[0, 1].imshow(array2)
axs[0, 1].set_title('Enduro')
axs[0, 2].imshow(array3)
axs[0, 2].set_title('Assault')


env1.close()
env2.close()
env3.close()

plt.show()
