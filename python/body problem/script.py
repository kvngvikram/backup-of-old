import numpy as np
import matplotlib.pyplot as plt

[x1,y1] = [0,0]
[x2,y2] = [10,0]
[x3,y3] = [0,0]

[x1d,y1d] = [0,-0.2]
[x2d,y2d] = [0,0.1]
[x2d,y2d] = [0,0.1]

[ma,mb,mc] = [1,2,3]

a = np.array([x1,y1])
b = np.array([x2,y2])
c = np.array([x3,y3])
ad = np.array([x1d,y1d])
bd = np.array([x2d,y2d])
ad = np.array([x3d,y3d])

G = 1

t = 0.1

ax = np.array([])
ay = np.array([])
bx = np.array([])
by = np.array([])
cx = np.array([])
cy = np.array([])

n = 1000
i = 0 
while i<n :
	a = a + t*ad
	b = b + t*bd
	c = c + t*cd 	
		
	ad = ad + t*(G*mb/(np.linalg.norm(b-a)**3))*(b-a) + t*(G*mc/(np.linalg.norm(c-a)**3))*(c-a) 
	bd = bd + t*(G*ma/(np.linalg.norm(a-b)**3))*(a-b) + t*(G*mc/(np.linalg.norm(c-b)**3))*(c-b)
	cd = cd + t*(G*ma/(np.linalg.norm(b-c)**3))*(a-c) + t*(G*mc/(np.linalg.norm(c-c)**3))*(c-c)

	ax = np.pad(ax,(0,1),'constant',constant_values = a[0])
	ay = np.pad(ay,(0,1),'constant',constant_values = a[1])
	bx = np.pad(bx,(0,1),'constant',constant_values = b[0])
	by = np.pad(by,(0,1),'constant',constant_values = b[1])
	
	i = i + 1

plt.figure(0)
plt.plot(ax,ay,'b')
plt.plot(bx,by,'r')
plt.show()
