import gym

from stable_baselines3 import DQN, PPO

# env = gym.make("LunarLander-v2")
env = gym.make("MountainCar-v0")

model = PPO("MlpPolicy", env, tensorboard_log='MountainCar')
model.learn(total_timesteps=1000000)
# model.save("dqn_cartpole")

# del model  # remove to demonstrate saving and loading
# model = DQN.load("dqn_cartpole")

# obs = env.reset()
# while True:
#     action, _states = model.predict(obs, deterministic=True)
#     obs, reward, done, info = env.step(action)
#     env.render()
#     if done:
#         obs = env.reset()
