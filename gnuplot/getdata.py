import numpy as np

x = np.linspace(-1,1,201)

print(x)

y = x**2

print(y)

np.savetxt('data.dat',np.c_[x,y],delimiter='\t')
