import numpy as np 
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit 


p = 1072.75882635   # peak position
s = 25.9343439121   # standard deviation for No lead

n = 2 		# limit of standard deviation to consider for integration i.e form p-n*sigma to p+n*sigma

data = np.genfromtxt('Na 22 5cm No lead.csv',delimiter=',')
xdata = data[:,0]
ydata = np.zeros((8,np.size(xdata)))
ydata[0,:] = data[:,1]
data = np.genfromtxt( 'Na 22 5cm 5mm lead.csv',delimiter=',')
ydata[1,:] = data[:,1]
data = np.genfromtxt('Na 22 5cm 10mm lead.csv',delimiter=',')
ydata[2,:] = data[:,1]
data = np.genfromtxt('Na 22 5cm 15mm lead.csv',delimiter=',')
ydata[3,:] = data[:,1]
data = np.genfromtxt('Na 22 5cm 20mm lead.csv',delimiter=',')
ydata[4,:] = data[:,1]
data = np.genfromtxt('Na 22 5cm 25mm lead.csv',delimiter=',')
ydata[5,:] = data[:,1]
data = np.genfromtxt('Na 22 5cm 30mm lead.csv',delimiter=',')
ydata[6,:] = data[:,1]
data = np.genfromtxt('Na 22 5cm 35mm lead.csv',delimiter=',')
ydata[7,:] = data[:,1]


integral = np.zeros(8)
dx = xdata[1]-xdata[0]

s = int(n*np.around(s/dx))
p = int(np.around(p/dx))

for i in range(8):
	for j in range(2*s):	
		integral[i] += ydata[i,(p-s+j)]


x = np.linspace(0,35,8)

def func(x , a ,b ,c ,d ):
	return a*np.exp(b*x+c)+d

popt, pcov = curve_fit(func, x , integral ,bounds=([0,-1000,-50,-1000],[1.3*np.max(integral),1000,50,1000]))

print(popt[1])
px = np.linspace(0,40,200)
plt.plot(px,func(px,*popt),label='Exponential fit')
plt.scatter(x,integral,color='red')
plt.title('Change in counts with thickness of Lead plates')
plt.xlabel('Thickness in mm')
plt.ylabel('Area of the peak')
plt.legend()

plt.show()
