import random 
import numpy as np
import matplotlib.pyplot as plt


# number of random walkers
W = 1000

# total number of steps taken by each walker
N = 100

# probabilities 
prob = np.array([1,2,3,4])

# right, left, up, and downward step variable for all the walkers, zero assigned initially
r = np.zeros(W)
l = np.zeros(W)
u = np.zeros(W)
d = np.zeros(W)

# average of right and upward distances of all the walkers after every step they make
xavg = np.zeros(N)
yavg = np.zeros(N)
# varience of right and upward distances of all the walkers after every step they make
xvar = np.zeros(N)
yvar = np.zeros(N)


# defining a function which can be called when ever a step is to be made by all the walkers
def step(r,u,l,d,W):
	for e in range(W): # e is for loop variable 
		a = random.choice(prob)         # generating a random integer between 1 to 4
		if a == 1 :
			r[e]=r[e]+1             # right
	#		print('right')
		elif a == 2 :
			u[e]=u[e]+1             # up
	#		print('up')
		elif a == 3 :
			l[e]=l[e]+1             # left 
	#		print('left')
		elif a == 4 :
			d[e]=d[e]+1             # downward
	#		print('down')




# taking N number of steps and calculating avg and var after each step
for i in range(N):
	step(r,u,l,d,W)        # All walkers take a random step
	xavg[i] = np.mean(r)   # Average of right steps of all the walkers 
	yavg[i] = np.mean(u)   # Average of upward steps of all the walkers
	xvar[i] = np.var(r)    # Varience of right steps of all the walkers
	yvar[i] = np.var(u)    # Varience of upward steps of all the walkers




# plotting the mean and variences corresponding to number of steps taken 
plt.subplots(22)

plt.subplot(221)
plt.plot(xavg,'g-')
plt.ylabel('Mean of right steps of all the walkers')
plt.title('Mean of right steps vs Number of steps')
#plt.xlabel('Number of steps')

plt.subplot(222)
plt.plot(yavg,'b-')
plt.ylabel('Mean of upward steps of all the walkers')
plt.title('Mean of upward steps vs Number of steps')
#plt.xlabel('Number of steps')

plt.subplot(223)
plt.plot(xvar,'r-')
plt.ylabel('Varience of right steps of all the walkers')
plt.title('Varience of right steps vs Number of steps')
plt.xlabel('Number of steps')

plt.subplot(224)
plt.plot(yvar,'y-')
plt.ylabel('Varience of upward steps of all the walkers')
plt.title('Varience of upward steps vs Number of steps')
plt.xlabel('Number of steps')

plt.show()

