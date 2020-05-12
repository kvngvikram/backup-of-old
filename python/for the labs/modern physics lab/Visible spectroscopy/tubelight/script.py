import numpy as np 
impport matplotlib.pyplot as plt

data = np.genfromtxt('ideal.csv',delimiter=',')
xdata = data[:,0]
cover = np.zeros(5,np.length(xdata))
cover[0,:] = data[:,1]
data = np.genfromtxt('1cover.csv',delimiter=',')
cover[1,:] = data[:,1]
data = np.genfromtxt('2cover.csv',delimiter=',')
cover[2,:] = data[:,1]
data = np.genfromtxt('3cover.csv',delimiter=',')
cover[3,:] = data[:,1]
data = np.genfromtxt('4cover.csv',delimiter=',')
cover[4,:] = data[:,1]

plt.subplot(151)
plt.plot(xdata,cover[0])

plt.subplot(152)
plt.plot(xdata,cover[1])

plt.subplot(153)
plt.plot(xdata,cover[2])

plt.subplot(154)
plt.plot(xdata,cover[3])

plt.subplot(155)
plt.plot(xdata,cover[4])

plt.show()
