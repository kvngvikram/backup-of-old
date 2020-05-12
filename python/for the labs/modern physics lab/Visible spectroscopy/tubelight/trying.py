import numpy as np 
import matplotlib.pyplot as plt


data = np.genfromtxt('idel.csv',delimiter=',')
ixdata = data[:,0]
iydata = data[:,1]

data = np.genfromtxt('transparent.csv',delimiter=',')
txdata = data[:,0]
tydata = data[:,1]

data = np.genfromtxt('paintblue.csv',delimiter=',')
bxdata = data[:,0]
bydata = data[:,1]

plt.figure()
plt.subplot(311)
plt.plot(ixdata,iydata)
plt.subplot(312)
plt.plot(txdata,tydata)
plt.subplot(313)
plt.plot(bxdata,bydata)
y1 = iydata-tydata
y2 = tydata-bydata
plt.figure()
plt.subplot(211)
plt.plot(ixdata,y1)
plt.subplot(212)
plt.plot(ixdata,y2)

plt.figure()
#plt.hold()
plt.plot(ixdata,iydata)
plt.plot(ixdata,tydata)
plt.plot(ixdata,bydata)

plt.show()