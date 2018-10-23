
# this code is for self avoiding random walkers 
# change the number of walkers and number of steps

import random 
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D


# number of random walkers
W = 1000

# total number of steps taken by each walker
N = 300

# probabilities 
prob = np.array([1,2,3,4])

# activity
active = np.ones(N)

# right, left, up, and downward step variable for all the walkers, zero assigned initially
r = np.zeros(W)
l = np.zeros(W)
u = np.zeros(W)
d = np.zeros(W)

# average of right and upward distances of all the walkers after every step they make
ravg = np.zeros(N)
uavg = np.zeros(N)
# varience of right and upward distances of all the walkers after every step they make
rvar = np.zeros(N)
uvar = np.zeros(N)

# x,y coordinates of first walker for plotting
x = np.array([r[0]-l[0]])
y = np.array([u[0]-l[0]])

p  = np.zeros((W,2*N+1,2*N+1))

# initially all the walkers are present at (0,0) 
# r-l = u-d = 0 for all the walkers initially
for e in range(W):
	p[e][int(N+(r[e]-l[e]))][int(N+(u[e]-d[e]))] = 1 

w = np.zeros(W)

#######################################################################################

# defining a function which can be called when ever a step is to be made by all the walkers
def step(r,l,u,d,W,w):
	for e in range(W): # e is for loop variable  		
		# figuring out not allowed cases 
		if (int(N+(r[e]-l[e]))+1)<2*N or (int(N+(u[e]-d[e]))+1)<2*N or (int(N+(r[e]-l[e]))-1)>=0 or (int(N+(u[e]-d[e]))-1)>=0:  		
			if p[e][int(N+(r[e]-l[e]))+1][int(N+(u[e]-d[e]))] > 0 : 
				a1 = 1 
			else : 
				a1 = 0
			if p[e][int(N+(r[e]-l[e]))][int(N+(u[e]-d[e]))+1] > 0 : 
				a2 = 2 
			else : 
				a2 = 0
			if p[e][int(N+(r[e]-l[e]))-1][int(N+(u[e]-d[e]))] > 0 : 
				a3 = 3 
			else : 
				a3 = 0
			if p[e][int(N+(r[e]-l[e]))][int(N+(u[e]-d[e]))-1] > 0 : 
				a4 = 4 
			else : 
				a4 = 0  		
		else : 
			a1 = 1 
			a2 = 2 
			a3 = 3 
			a4 = 4 
	
		if  not(a1==1 and a2 == 2 and a3 == 3 and a4 == 4): 
			a = random.choice(prob)
			while a1 == a or a2 == a or a3 == a or a4 == a: 
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
			if (int(N+(r[e]-l[e])))<2*N or (int(N+(u[e]-d[e])))<2*N or (int(N+(r[e]-l[e])))>=0 or (int(N+(u[e]-d[e])))>=0:
				p[e][int(N+(r[e]-l[e]))][int(N+(u[e]-d[e]))] += 1 
		else : 
			w[e] = 1 
#		print e 
#######################################################################################



# taking N number of steps
i = 0
active[0] = W 
while i < N and not(active[i-1]==0) : 
	step(r,l,u,d,W,w)   # all the walkers take one random step
	n = r-l           # position of each walker on x axis 
	m = u-d	          # position of each walker on y axis
	x = np.pad( x, (0,1), 'constant', constant_values = n[0] ) # increasing array size of x, y of first particle to include the latest motion 
	y = np.pad( y, (0,1), 'constant', constant_values = m[0] )
	active[i] = W - np.sum(w)	
	ravg[i] = np.mean(r)
	uavg[i] = np.mean(u)
	rvar[i] = np.var(r)
	uvar[i] = np.var(u)
	if active[i] == 0:
		i += 1 			
		break

	# dynamic plot
	plt.figure(0)	
	plt.clf()         # refreshing the plot for each step
	plt.axis([-N/3,N/3,-N/3,N/3])      # defining range of axis
	plt.scatter(n, m , s=0.5 , c='r')    # displaying the position of each walker
	plt.plot(x,y)
	plt.xlabel('horizontal position')
	plt.ylabel('vertical position')
	plt.title('Movement of 2D random walkers')

	plt.pause(0.00001)                   # time delay for each step in seconds 
	i += 1 


stoppedat = i
print (stoppedat)

############################################################################
# for the 3D histogram

b = 100
br = N
g = np.zeros([b,b,N])
for j in range(W):
	hx = int(np.around(((b/2)*n[j])/br)+(b/2)-1)
	hy = int(np.around(((b/2)*m[j])/br)+(b/2)-1)
	g[hx][hy][i-1] += 1 
 
data_array = np.array(g[:,:,int(stoppedat-1)])
fig = plt.figure(1)
plt.clf()
ax = fig.add_subplot(111, projection='3d')
x_data, y_data = np.meshgrid( np.arange(data_array.shape[1]),np.arange(data_array.shape[0]) )
x_data = x_data.flatten()
y_data = y_data.flatten()
z_data = data_array.flatten()
ax.bar3d( x_data,y_data,np.zeros(len(z_data)),0.5, 0.5, z_data,'r' )
############################################################################


while i<N : 
	active[i] = W - np.sum(w)	
	ravg[i] = np.mean(r)
	uavg[i] = np.mean(u)
	rvar[i] = np.var(r)
	uvar[i] = np.var(u)
	i += 1 

 





plt.figure(2)
plt.plot(1-active/W)
plt.xlabel('Number of steps taken')
plt.ylabel('Probability ')
plt.title('Probability that a walker will stop after N steps')


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






	



