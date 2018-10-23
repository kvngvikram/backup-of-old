import numpy as np 
import matplotlib.pyplot as plt
string = input('\n\nenter the name of the data file : ')
data = np.genfromtxt(string,delimiter=',')
xdata=data[:,0]
ydata = data[:,1]
plt.plot(xdata,ydata)
plt.show()
