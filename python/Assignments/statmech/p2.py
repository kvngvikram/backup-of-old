# path avoiding random walkers 
# set the number of walkers and number of steps

import random 
import numpy as np
import matplotlib.pyplot as plt


# number of random walkers
W = 100

# total number of steps taken by each walker
N = 200

# array storing the outputs of the random function
# for changing the probability change the number of similar elements in this array
# each element in array has equal probability
prob = np.array([1,2,3,4])

# right, left, up, and downward step variable for all the walkers, zero assigned initially
r = np.zeros(W)
l = np.zeros(W)
u = np.zeros(W)
d = np.zeros(W)

# x,y coordinates of first walker for plotting
x = np.array([r[0]-l[0]])
y = np.array([u[0]-l[0]])


# storing the previous steps of each walker
mb = np.zeros((W,2*N+1,2*N+1)) 	 # stores previous step of particular walker at particular point in 2D plane
ma = np.zeros((W,2*N+1,2*N+1))	 # stores the next step taken from by particular walker from that particular point in 2D plane
mc = np.zeros((W,2*N+1,2*N+1))	 # stores previous step of particluar walker at particular point in 2D plane when walker comes to that point for second time 
p  = np.zeros((W,2*N+1,2*N+1)) 	 # number of times that particular walker visited that particular point in 2D plane


# average of right and upward distances of all the walkers after every step they make
ravg = np.zeros(N)
uavg = np.zeros(N)
# varience of right and upward distances of all the walkers after every step they make
rvar = np.zeros(N)
uvar = np.zeros(N)



# defining a function which can be called when ever a step is to be made by all the walkers
def step(r,l,u,d,W,mb,ma,mc,p):
	for e in range(W): # e is for loop variable 
		a = random.choice(prob) # get a random direction (1,2,3,4)
		# while loop rund again and again until we get a different a which doesn't lead to going back or repeating the step 
		while mb[e][int(N+(r[e]-l[e]))][int(N+(u[e]-d[e]))] == a or ma[e][int(N+(r[e]-l[e]))][int(N+(u[e]-d[e]))] == a or mc[e][int(N+(r[e]-l[e]))][int(N+(u[e]-d[e]))] == a :
				a = random.choice(prob)  # be called again and again till it gets different move
			
		
		# counting number of times the spot is visited 
		p[e][int(N+(r[e]-l[e]))][int(N+(u[e]-d[e]))] += 1 
		# further move done by particular walker from this point 
		ma[e][int(N+(r[e]-l[e]))][int(N+(u[e]-d[e]))] = a 
		#print(ma[e][int(N+(r[e]-l[e]))][int(N+(u[e]-d[e]))])
		if p[e][int(N+(r[e]-l[e]))][int(N+(u[e]-d[e]))] < 3 : # no one can come to same point 3 times, if he comes he should not move anywhere 	
			if a == 1 :
				r[e]=r[e]+1   # number of right steps incremented
		#		print('right')
				if p[e][int(N+(r[e]-l[e]))][int(N+(u[e]-d[e]))] != 1 : # if p = 0 or spot is not yet visited then assign mb
					mb[e][int(N+(r[e]-l[e]))][int(N+(u[e]-d[e]))] = 3 # no left from here because it came from left before
				else : # if spot is already visited then p = 1 and don't change mb , assign mc now 
					mc[e][int(N+(r[e]-l[e]))][int(N+(u[e]-d[e]))] = 3 # no left from here because it came from left before
			elif a == 2 :
				u[e]=u[e]+1
		#		print('up')
				if p[e][int(N+(r[e]-l[e]))][int(N+(u[e]-d[e]))] != 1 :
					mb[e][int(N+(r[e]-l[e]))][int(N+(u[e]-d[e]))] = 4
				else :
					mc[e][int(N+(r[e]-l[e]))][int(N+(u[e]-d[e]))] = 4 
			elif a == 3 :
				l[e]=l[e]+1
		#		print('left')
				if p[e][int(N+(r[e]-l[e]))][int(N+(u[e]-d[e]))] != 1 :
					mb[e][int(N+(r[e]-l[e]))][int(N+(u[e]-d[e]))] = 1
				else :
					mc[e][int(N+(r[e]-l[e]))][int(N+(u[e]-d[e]))] = 1 
			elif a == 4 :
				d[e]=d[e]+1
		#		print('down')
				if p[e][int(N+(r[e]-l[e]))][int(N+(u[e]-d[e]))] != 1 :
					mb[e][int(N+(r[e]-l[e]))][int(N+(u[e]-d[e]))] = 2
				else :
					mc[e][int(N+(r[e]-l[e]))][int(N+(u[e]-d[e]))] = 2 






# taking N number of steps
for i in range(N):
	step(r,l,u,d,W,mb,ma,mc,p)   # all the walkers take one random step
	n = r-l           # position of each walker on x axis 
	m = u-d	          # position of each walker on y axis	
	x = np.pad( x, (0,1), 'constant', constant_values = n[0] ) # increasing array size of x, y of first particle to include the latest motion 
	y = np.pad( y, (0,1), 'constant', constant_values = m[0] )
	ravg[i] = np.mean(r)
	uavg[i] = np.mean(u)
	rvar[i] = np.var(r)
	uvar[i] = np.var(u)
	plt.figure(0)
	plt.clf()         # refreshing the plot for each step
	plt.axis([-N/4,N/4,-N/4,N/4])      # defining range of axis
	plt.scatter(n, m , s=3 , c='r')    # displaying the position of each walker
	plt.plot(x,y)	
	plt.xlabel('horizontal position')
	plt.ylabel('vertical position')
	plt.title('Movement of 2D random walkers')
	plt.pause(0.0001)                   # time delay for each step in seconds 




plt.subplots(22)
plt.subplot(221)
plt.axis([0,N*11/10,0,N*3/10])
plt.plot(ravg,'g-')
plt.ylabel('Mean of right steps of all the walkers')
plt.title('Mean of right steps vs Number of steps')
#plt.xlabel('Number of steps')
plt.subplot(222)
plt.axis([0,N*11/10,0,N*3/10])
plt.plot(uavg,'b-')
plt.ylabel('Mean of upward steps of all the walkers')
plt.title('Mean of upward steps vs Number of steps')	
#plt.xlabel('Number of steps')
plt.subplot(223)
plt.axis([0,N*11/10,0,N*2])
plt.plot(rvar,'r-')
plt.ylabel('Varience of right steps of all the walkers')
plt.title('Varience of right steps vs Number of steps')
plt.xlabel('Number of steps')
plt.subplot(224)
plt.axis([0,N*11/10,0,N*2])
plt.plot(uvar,'y-')
plt.ylabel('Varience of upward steps of all the walkers')
plt.title('Varience of upward steps vs Number of steps')
plt.xlabel('Number of steps')
plt.show()






	



