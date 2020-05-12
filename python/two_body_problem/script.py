import numpy as np
import matplotlib.pyplot as plt

[x1,y1] = [0,0]
[x2,y2] = [10,0]

[x1d,y1d] = [0,-0.2]
[x2d,y2d] = [0,0.1]

[ma,mb] = [1,2]

a = np.array([x1,y1])
b = np.array([x2,y2])
ad = np.array([x1d,y1d])
bd = np.array([x2d,y2d])

G = 1

t = 0.1

ax = np.array([])
ay = np.array([])
bx = np.array([])
by = np.array([])

n = 1000
i = 0 
while i<n :
	a = a + t*ad
	b = b + t*bd
	
	ad = ad + t*(G*mb/(np.linalg.norm(b-a)**3))*(b-a) 
	bd = bd + t*(G*ma/(np.linalg.norm(b-a)**3))*(a-b) 
	
	ax = np.pad(ax,(0,1),'constant',constant_values = a[0])
	ay = np.pad(ay,(0,1),'constant',constant_values = a[1])
	bx = np.pad(bx,(0,1),'constant',constant_values = b[0])
	by = np.pad(by,(0,1),'constant',constant_values = b[1])
	
	i = i + 1

plt.figure(0)
plt.plot(ax,ay,'b')
plt.plot(bx,by,'r')
plt.show()
