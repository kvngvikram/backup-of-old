import numpy as np 
import matplotlib.pyplot as plt

data = np.genfromtxt('ref.csv',delimiter=',')
xdata = data[:,0]
ideal = data[:,1]

data = np.genfromtxt('withoutwater.csv',delimiter=',')
nowater = data[:,1]
data = np.genfromtxt('withwater.csv',delimiter=',')
water = data[:,1]

plt.figure(0)
plt.subplot(311)
plt.axis([xdata[0],xdata[np.size(xdata)-1],np.min(ideal),np.max(ideal)])
plt.plot(xdata,ideal)
plt.subplot(312)
plt.axis([xdata[0],xdata[np.size(xdata)-1],np.min(ideal),np.max(ideal)])
plt.plot(xdata,nowater)
plt.subplot(313)
plt.axis([xdata[0],xdata[np.size(xdata)-1],np.min(ideal),np.max(ideal)])
plt.plot(xdata,water)

plt.show()
