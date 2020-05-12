import pandas as pd
import numpy as np

filename = 'data.txt'
mywidths = [8, 5, 3, 19, 19, 11, 11, 14, 14]
data = pd.read_fwf(filename,widths=mywidths,header=None,skiprows=3)
print(data)

npdata = np.asarray(data)
print(npdata)
print(npdata[:,1:7])
np.savetxt('temp.dat',npdata[:,1:7],delimiter=' ')
