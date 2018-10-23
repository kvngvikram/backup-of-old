import random 
import numpy as np
import matplotlib.pyplot as plt


# number of random walkers
W = 200

# total number of steps taken by each walker
N = 50

#probabilities
prob = np.array([1,2])

r = np.zeros(W)    # right step variable for all the walkers, zero assigned initially
l = np.zeros(W)	   # left step variable for all the walkers, zero assigned initially
avg = np.zeros(N)  # average of right distances of all the walkers at every time interval till N steps
var = np.zeros(N)  # varience fo right distances of all the walkers at every time interval till N steps


# defining a function which can be called when ever a step is to be made by all the walkers
def step(r,l,W):
	# for each and every walker found out weather he goes right or left in for loop
	for e in range(W): # e is for loop variable and W is number of walkers
		a = random.choice(prob) # generating a random intezer between 1 and 2 
		if a == 1 :             # if 0 is obtained that particular walker numbered e goes right
			r[e]=r[e]+1     # number of right steps taken by that walker is incremented
	#		print('right')
		elif a == 2 :           # if 1 is obtained that particular walker numbered e goes left
			l[e]=l[e]+1     # number of right steps taken by that walker is incremented
	#		print('left')




# taking N number of steps and calculating avg and var after each step
for i in range(N):
	step(r,l,W)          # All the walkers take one random step
	avg[i] = np.mean(r)  # Average/mean of positions of all the walkers after i steps or time
	var[i] = np.var(r)   # Varience of positions of all the walkers after i steps or time


# plotting the mean and varience after corresponding number of steps

plt.figure('Mean')
plt.plot(avg,'g-')
plt.title('Mean vs number of steps')
plt.xlabel('Number of steps')
plt.ylabel('Mean of right steps of all the walkers')

plt.figure('Varience')
plt.plot(var , 'r-')
plt.title('Varience vs number of steps')
plt.xlabel('Number of steps')
plt.ylabel('Varience of right steps of all the walkers')

plt.show()
