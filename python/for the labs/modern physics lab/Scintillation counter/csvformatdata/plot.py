import numpy as np 
import matplotlib.pyplot as plt

string = input('Type the file name of the data\n')
data = np.genfromtxt(string,delimiter=',')
xdata=data[:,0]
ydata = data[:,1]
plt.plot(xdata,ydata)
plt.title(string)
plt.xlabel('channel number')
plt.ylabel('number of counts')
plt.show()
