import random 
import numpy as np
import matplotlib.pyplot as plt


# number of random walkers
W = 1000

# total number of steps taken by each walker
N = 100

# probabilities 
prob = np.array([1,2,3,4,2])

# right, left, up, and downward step variable for all the walkers, zero assigned initially
r = np.zeros(W)
l = np.zeros(W)
u = np.zeros(W)
d = np.zeros(W)


# defining a function which can be called when ever a step is to be made by all the walkers
def step(r,l,u,d,W):
	for e in range(W): # e is for loop variable 
		a = random.choice(prob)
		if a == 1 :
			r[e]=r[e]+1
	#		print('right')
		elif a == 2 :
			u[e]=u[e]+1
	#		print('up')
		elif a == 3 :
			l[e]=l[e]+1
	#		print('left')
		elif a == 4 :
			d[e]=d[e]+1
	#		print('down')





# taking N number of steps
for i in range(N):
	step(r,l,u,d,W)   # all the walkers take one random step
	n = r-l           # position of each walker on x axis 
	m = u-d	          # position of each walker on y axis
	plt.clf()         # refreshing the plot for each step
	plt.axis([-N/4,N/4,-N/4,N/4])      # defining range of axis
	plt.scatter(n, m , s=1 , c='b')    # displaying the position of each walker
	plt.xlabel('horizontal position')
	plt.ylabel('vertical position')
	plt.title('Movement of 2D random walkers')
	plt.pause(0.001)                   # time delay for each step in seconds 


while True:
    plt.pause(0.05)







	



