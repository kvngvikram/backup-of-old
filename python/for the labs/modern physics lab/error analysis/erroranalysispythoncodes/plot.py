import numpy as np 
import matplotlib.pyplot as plt

ydata = np.genfromtxt('data.csv',delimiter=',')


plt.plot(ydata,'.',markersize=1)
plt.show()
