X = 10
K = 4
T = 10 
dX = float(X)/25
dT = float(T)/501
print(X)
print(T)
print(dX)
print(dT)

import numpy as np
import matplotlib.pyplot as plt


S = np.zeros((int(T/dT+1),int(X/dX+1)))
A = np.zeros((int(T/dT+1),int(X/dX+1)))


x = np.linspace(0,X,X/dX+1)
t = np.linspace(0,T,T/dT+1)
print(x)
S[0,:] = np.sin(np.pi*x/float(X))
print(np.shape(S))

r = K*dT/float(dX**2)
for j in np.linspace(1,X/dX-1,X/dX-1).astype(int) : 	# Space
#		print(i,j) 
	S[1,j] = r*(S[0,j+1]-2*S[0,j]+S[0,j-1])+S[0,j]
	
r2 = r*2
r3 = r2/(1+r2)
for i in np.linspace(2,T/dT-1,T/dT-2).astype(int): 	# Time 
	for j in np.linspace(1,X/dX-1,X/dX-1).astype(int) : 	# Space
#		print(i,j) 
		S[i,j] = r3*(S[i-1,j+1]-S[i-2,j]+S[i-1,j-1])+(1/(1+r2))*S[i-2,j]
	
	A[i,:] = np.exp(-K*((np.pi/X)**2)*(i*dT))*np.sin(np.pi*x/float(X))

plt.figure(0)	
for i in np.linspace(1,T/dT-1,T/dT-1).astype(int): 	# Time 
	plt.clf()
	plt.axis([0,10,0,1])
	plt.plot(x,S[i,:],'b')
	plt.plot(x,A[i,:],'r')
	plt.legend()
	plt.show(block=False)
	plt.pause(0.000000000001)

plt.show(block=True)
