#!/
import gym
import torch
import torch.nn as nn
import numpy as np

# LunarLander离散action space环境
env = gym.make('LunarLander-v2')
env.seed(0)
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
        ])
    
        
    def forward(self, x):
        pass
    

if __name__ == '__main__':
    print(env.action_space)
    print(env.observation_space)