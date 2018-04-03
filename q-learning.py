import numpy as np
import random

world = [0,0,0,0,0,0,0,0,0]
cur_pos = random.randint(0, 9)
actions = ['left', 'right']

def build_table():


def updata_world():
    world = [0, 0, 0, 0, 0, 0, 0, 0, 0]
    seed = random.randint(0,8)
    world[seed] = 1

def step(action):
    state = cur_pos
    reward = 0

    if world[state] == 1:
        reward = 1
        return state, reward

    if action is 'left':
        if state == 0:
            pass
        else:
            state -= 1
            if world[state] == 1:
                reward == 1
                updata_world()
    elif action is 'right':
        if state == 8:
            pass
        else:
            state += 1
            if world[state] == 1
                reward == 1
                updata_world()
    else:
        print('pass the wrong action')

    return state, reward

