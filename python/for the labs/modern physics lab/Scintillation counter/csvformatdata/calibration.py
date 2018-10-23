import numpy as np 
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

string = input("\n\nType the file name of the data : ")
data = np.genfromtxt(string,delimiter=',')
xdata=data[:,0]
ydata = data[:,1]
plt.figure(0)

plt.plot(xdata,ydata)
plt.title(string)
plt.xlabel('channel number')
plt.ylabel('number of counts')
plt.show(block = False)
plt.pause(0.01)

res = xdata[1]-xdata[0]

def func(x,a,b,c,d,e):
	return a*np.exp(-((x-b)**2)/c)+d*x +e

choice = True;
while choice : 
	#start = 2300 
	#stop = 2500
	start = input('\n\nenter x coordinate of start point for gaussian : ')
	stop = input('\nenter x coordinate of ending point for gaussian : ')
	start = float(start)/float(res)
	stop = float(stop)/float(res)
	fx = xdata[int(start):int(stop+1)]
	fy = ydata[int(start):int(stop+1)]
	popt, pcov = curve_fit(func,xdata,ydata,bounds=([0,start,0,-1000,-1000],[100000,stop,100000,1000,1000]))
	print('\n\nX coordinate of the peak is : ')	
	print(popt[1])
	print('\nStandard deviation of gaussian : ')
	print((popt[2]/2)**0.5)
	plt.figure(0)
	plt.plot(fx,func(fx,*popt),color='red',linewidth = '3')
	plt.show(block = False)
	inp = int(input('\n\nDo you want to fit another gaussian ? 1/0  : '))
	choice = (inp==1)
	

print('\n\nThanks for stopping by, enjoy the graphs and note down the values\n')

print('This is how vikram does the hutiyapa')
plt.show()
