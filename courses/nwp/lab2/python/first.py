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


S = np.zeros((int(T/dT+1),int(X/dX)))
A = np.zeros((int(T/dT+1),int(X/dX+1)))


x = np.linspace(0,X,X/dX)
t = np.linspace(0,T,T/dT+1)
print(x)
S[0,:] = np.sin(np.pi*x/float(X))
print(np.shape(S))

r = K*dT/float(dX**2)

a = r 
b = -(2*r+1)
c = r 

row = np.zeros(int(X/dX-1))
'''
row[0] , row[1] = b , c 
S2 = np.zeros((int(X/dX-1),int(X/dX-1)))
S2[0,:] = row

row[0] , row[1] , row[2]  = a ,  b , c 

S2[1,:] = row

ia = np.asarray(range(int(X/dX-3)))+2
ja = np.asarray(range(int(X/dX-1)))
for i in ia :
    for j in ja:
        S2[i,j] =  S2[i-1,j-1]
'''

Ad = np.zeros((int(X/dX-1),3))
print(np.shape(Ad))
ia = np.asarray(range(int(X/dX-3)))+1
Ad[0,0] , Ad[0,1] , Ad[0,2] = 0 , b , c
Ad[int(X/dX-2),0] , Ad[int(X/dX-2),1] , Ad[int(X/dX-2),2] = a , b , 0
for i in ia : 
    Ad[i,0] , Ad[i,1] , Ad[i,2] = a , b , c 
print(Ad)

cp = np.zeros(int(X/dX-1))
cp[0]=c/b
ia = np.asarray(range(int(X/dX-2)))+1
for i in ia : 
    cp[i] = c/(b-a*cp[i-1])


dp = np.zeros(int(X/dX-2))
print(np.shape(dp))
dp[:] = S[0,1:int(X/dX-1)]
print(dp)
ia = np.asarray(range(int(T/dT-2)))+1
for i in ia : 
    tdp = dp
    tdp[0] = tdp[0]/b
    for j in np.asarray(range(np.size(tdp)-1))+1 : 
        tdp[j] = (tdp[j]-a*tdp[j-1])/(b-a*cp[j-1])

    nX = tdp
   
    for j in np.asarray(range(np.size(nX)-1))+1 : 
        li = np.size(nX)-j-1
        nX[li] = nX[li] - cp[li]*nX[li+1]
    d = nX
    S[i,1:int(X/dX-1)] = nX


 
plt.figure(0)	
for i in range(int(T/dT-1)) : 	# Time 
	plt.clf()
	plt.axis([0,X,0,1])
	plt.plot(x,S[i,:],'b')
	plt.legend()
	plt.show(block=False)
	plt.pause(0.000000000001)

plt.show(block=True)

'''
Ap = np.zeros((int(X/dX-1),3))
#print(np.shape(Ap))
ia = np.asarray(range(int(X/dX-3)))+1
#print(i)
Ad[0,0] , Ad[0,1] , Ad[0,2] = 0 , b , c
Ad[int(X/dX-2),0] , Ad[int(X/dX-2),1] , Ad[int(X/dX-2),2] = a , b , 0
for i in ia : 
    Ad[i,0] , Ad[i,1] , Ad[i,2] = a , b , c 
#print(Ad)
'''
    

