import numpy as np
import matplotlib.pyplot as plt 

def func(x,c):
    return np.sin(x*c)

c = 1 
x = np.linspace(0,2*np.pi,100)
y = func(x,c)

plt.scatter(x,y)


initial_guess = 0.6
c = initial_guess
Y = np.asmatrix(y).T
#print(Y)
matrix = x*np.cos(x*c)
X = np.asmatrix(matrix).T
#print(X)


delta = (X.T*X).I*X.T*(Y-np.asmatrix(func(x,c)).T)
c = c+np.asarray(delta)[:,0]
matrix = x*np.cos(x*c)
X = np.asmatrix(matrix).T
plt.plot(x,func(x,c))




plt.show()


