#!/usr/bin/env python
# coding: utf-8

# # 1.	Gather and Set the Instruments 
# a.	Laptop: Sony Vaio F
#     •	CPU: Intel(R) core (TM) i7-2720QM CPU @ 2.20GHz (8 CPUs)
#     •	RAM: 8GB ram
#     •	DirectX version: Direct X 11
#     •	Operating system: Windows 7 Ultimate 64 bits
#     •	GPU: NVIDIA GeForce GT540M
#         o	Driver version: 391.35
#         o	CUDA version: 9.1.84 driver
#             	CUDA cores: 96
#     •	Memory available: 16.8 GB free of 445GB
#     
# b.	ANACONDA commercial edition
#     •	IDE: Jupyter notebook
#     
# c.	Web Browser: Microsoft Edge
# 
# d.	Visual Studio Build Tools: 2019
# 
# e.	Programming language: Python
#     •	Library: Stable-Baseline3

# # 2.	Import the dependencies
# a.	Install the box2d gym.
# b.	Install stable-baselines3
# c.	Importing the gym
# d.	Importing OS module
# e.	Import the dependencies from stable_baselines3. 

# In[1]:


get_ipython().system('pip install gym[box2d] pyglet')


# In[2]:


get_ipython().system('pip install stable-baselines3[extra]')


# In[1]:


import gym
import os
from stable_baselines3 import DQN
from stable_baselines3.common.vec_env import DummyVecEnv
from stable_baselines3.common.evaluation import evaluate_policy


# # 3.	Set and Test the Environment 

# In[2]:


environment_name = "LunarLander-v2"
env = gym.make(environment_name)


# In[3]:


env = gym.make(environment_name)


# In[6]:


episodes = 10
for episode in range(1, episodes+1):
   state = env.reset()
   done = False
   score = 0 
    
   while not done:
        env.render()
        action = env.action_space.sample()
        n_state, reward, done, info = env.step(action)
        score+=reward
   print('Episode:{} Score:{}'.format(episode, score))
env.close()


# In[12]:


env.action_space


# In[13]:


env.action_space.sample()


# Actions that the agent can take
# 
# 0: Do nothing
# 1: Fire left engine
# 2: Fire down engine
# 3: Fire right engine

# In[14]:


env.observation_space


# In[15]:


env.observation_space.sample()


# What the agent can observe 
# 
# state	
# 
# horizontal position,	vertical position,	
# horizontal velocity,	vertical velocity,	
# angle velocity,	        angular velocity,	
# left leg contact,	    right leg contact

# # 4.	Train the model 

# In[4]:


env = gym.make(environment_name)


# In[5]:


env = DummyVecEnv([lambda: env])


# In[6]:


log_path = os.path.join('Training', 'Logs')


# In[7]:


model = DQN('MlpPolicy', env, verbose = 1, tensorboard_log=log_path)


# ![image.png](attachment:image.png)

# Default hyper parameters of the DQN of stable-baselines3
# ![image.png](attachment:image.png)

# ![image.png](attachment:image.png)

# In[8]:


model.learn(total_timesteps=100000)


# # 5.	Save the model

# In[19]:


dqn_path = os.path.join('Training', 'Saved Models', 'best_model')


# In[18]:


model.save(dqn_path)


# For loading a model

# In[20]:


model = DQN.load(dqn_path, env = env)


# For deleting the model

# In[22]:


del model


# # 6.	Evaluate and test the model

# In[34]:


evaluate_policy(model, env, n_eval_episodes=10, render=True)


# In[35]:


env.close()


# Testing the model in an encapsulating function

# # Testing

# define an environment
# train the model
# evaluate and test

# In[21]:


episodes = 10
for episode in range(1, episodes+1):
   obs = env.reset()
   done = False
   score = 0 
    
   while not done:
        env.render()
        action, _ = model.predict(obs)
        obs, reward, done, info = env.step(action)
        score+=reward
   print('Episode:{} Score:{}'.format(episode, score))
env.close()


# # Logs

# In[5]:


training_log_path = os.path.join(log_path, 'DQN_3')


# In[ ]:


get_ipython().system('tensorboard --logdir={training_log_path}')


# # Callback

# Callback for model 4
# Stops training after reward threshold

# In[84]:


from stable_baselines3.common.callbacks import EvalCallback, StopTrainingOnRewardThreshold


# In[90]:


save_path = os.path.join('Training', 'Saved Models', 'RL_model_withCallback')


# In[93]:


stop_callback = StopTrainingOnRewardThreshold(reward_threshold=200, verbose=1)


# In[94]:


eval_callback = EvalCallback(env,callback_on_new_best=stop_callback,eval_freq=10000,best_model_save_path=save_path,verbose=1)


# model training with callback

# In[95]:


model.learn(total_timesteps=3000000, callback=eval_callback)


# In[ ]:




