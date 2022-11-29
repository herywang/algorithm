#!/Users/wangheng/app/anaconda3/envs/gym/bin/python

import pybullet as p
from time import sleep
from pybullet_envs.bullet import CartPoleBulletEnv

# cid = p.connect(p.DIRECT)
env = CartPoleBulletEnv(renders=True, discrete_actions=False)

env.render()
env.reset()

print(env.action_space)

for _ in range(10000):
    sleep(1 / 60)
    action = env.action_space.sample()
    obs, reward, done, _ = env.step(action)
    print(action)
    if done:
        break

# p.disconnect(cid)
