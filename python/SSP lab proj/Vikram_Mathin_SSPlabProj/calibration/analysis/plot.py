import numpy as np 
import matplotlib.pyplot as plt

string = raw_input('Type the file name of the data\n')
data = np.genfromtxt(string,delimiter=',')
plt.plot(data)
plt.title(string)
plt.xlabel('channel number')
plt.ylabel('number of counts')
plt.show()
