#import the packages, if they are not installed initially then install them
import numpy as np
import matplotlib.pyplot as plt 
from scipy.optimize import curve_fit

#load the measurement data into the variable ydata
#data should be present in the .csv file in the first column and the data points should be seperated by comma i.e. ','
ydata = np.genfromtxt('charging.csv',delimiter=',') #data file should be saved in same folder of his script.py file

#define the time points starting from 0 seconds to the time the measurements are taken
#number of elements in xdata array should be equal to that of ydata and seperated by time given by horizontal resolution mentioned in the data file
#initial time = 0, final time is second aurgument calculated by number of samples and sampling period, third aurgument is number of elements
xdata = np.linspace(0,np.size(ydata)*1.6/1000000000,np.size(ydata)) 


#Actual time constant from values of resistor and capacitor
#T = 47e-7


#defining a general exponential function, x is the variable and a, b, c and d are parameters
def func(x,a,b,c,d):
	return a+b*np.exp(c*x-d) 


#fitting the general exponential function to the measured data
#first variable 'popt' is array of the fitted parameters, second variable 'pcov' is a 4*4 covarience matrix
#give the bounds to the parameters so that execution don't do large number of iterations and give error
popt, pcov = curve_fit(func,xdata,ydata,bounds=([-2,-2,-300000,-10000],[2,2,-100000,10000]))


#print the fitted parameters 
print ('for the exponential fit\n')
print (popt) 
print ('\n')
print (pcov)
print ('\n')


#defining an array of the correct values of y (Voltage) according to the fitting
#second aurgument to func is the fitted parameters popt
y = func(xdata,*popt)


#plotting the data and its fit in the same figure window '0'  
plt.figure(0)
plt.title('Discharging')
plt.plot(xdata,ydata,'p',markersize=0.5) #'p' for marking points instead of interpolating, markersize is size of the data points
plt.plot(xdata,y,'g-',label='exponential fit curve') #'g-' is colour green and continuous curve
#plt.plot(xdata,func(xdata,1,-2,-1/T,(popt[3])/popt[2]),'r-',label='theoretical curve')
plt.xlabel('time in seconds')
plt.ylabel('Voltage across capacitor')
plt.legend()
#plt.show() 






 
#now we are checking if errors from the data to fitted curve follow normal distribution
number_of_bars = 40    #number of bars (in bar graph) in the normal distrubution curve 
error_range = 0.3     #range of errors i.e. from (-error_range , +error_range)
	#'IndexError: index 30 is out of bounds for axis 0 with size 30'
	#if the above kind of error is displayed increase the error range



#for plotting error distribution at different parts (3 here) of data we give three start points and three end points to start and end with  
first_startpoint = 0   #frist error curve will start from startpoint numbered data point(measured)
first_endpoint = 1000  #first error curve will be till the endpoint numbered data point(measured)
second_startpoint =4500  #similarly for all the three parts of the data
second_endpoint = 5500
third_startpoint = 9000 
third_endpoint = 10000



a= number_of_bars  #its a lenthy name
l=error_range

#defining the x,y axis variables in error graph
n = np.linspace(-l,l,a) #units: voltage

#g is number of data points having error of n (on x axis), assigned zero initially will be counted soon
#this is for all the data points
g = np.zeros(a)         #units: no unitsnumber of data points having error of n (on x axis), assigned zero initially


#for different parts of the data
g1 = np.zeros(a)
g2 = np.zeros(a)
g3 = np.zeros(a)


#error or deviation of each data point from the fitted value
e = y - ydata 


#counting values of g
i = 0 #starting from the 0th element or first data point
while i<np.size(e): #till the last datapoint
	
	#h is the index of the element in g that should be added by one 
	#each data point comes under a particular h depending on its deviaton from the fitted curve
	#h is going to be the index so it should be an integer, so it is typecasted as int()
	#map each error to its position on x axis of error graph (x axis has error) and find the position it is supposed to be in error graph
	#and round off its position value to an integer using 'np.around()'
	# '-1' in the end because indexing starts from '0' not '1'
	#'a' is the number of bars, half of them will be on either side of zero error. The gaussian curve should be symmetric about zero ideally
	h = int(np.around(((a/2)*e[i])/l)+(a/2)-1) 	
	g[h] = g[h] + 1 #corresponding g is added with one
	i = i+1		#repeating this process for all the data points



#repeating the same process of above for different parts of data
i = first_startpoint
while i<first_endpoint:
	h = int(np.around(((a/2)*e[i])/l)+(a/2)-1)
	g1[h] = g1[h] + 1
	i = i+1 


i = second_startpoint
while i<second_endpoint:
	h = int(np.around(((a/2)*e[i])/l)+(a/2)-1)
	g2[h] = g2[h] + 1
	i = i+1 


i = third_startpoint
while i<third_endpoint:
	h = int(np.around(((a/2)*e[i])/l)+(a/2)-1)
	g3[h] = g3[h] + 1
	i = i+1 



#defining a general gaussian function
def gfunc(x,a,b,c,d):
	return a*np.exp(-b*np.square(x-c))+d


#fitting the data of errors into general gaussian function
#upper bounts are decided by the maximum possible value (for a = 1), but these can be any higher value and can be decided by trails
gpopt, gpcov = curve_fit(gfunc,n,g,bounds=([0,0,-0.5,-100],[np.size(y)+1,np.square(0.5*a/l),0.5,100]))
g1popt, g1pcov = curve_fit(gfunc,n,g1,bounds=([0,0,-0.5,-100],[np.size(y)+1,np.square(0.5*a/l),0.5,100]))
g2popt, g2pcov = curve_fit(gfunc,n,g2,bounds=([0,0,-0.5,-100],[np.size(y)+1,np.square(0.5*a/l),0.5,100]))
g3popt, g3pcov = curve_fit(gfunc,n,g3,bounds=([0,0,-0.5,-100],[np.size(y)+1,np.square(0.5*a/l),0.5,100]))


#printing 
print ('for the gaussian\n')
print (gpopt) 
print ('\n')




#plotting error curve for all the data
plt.figure(1) #second figure window
plt.title('Normal error distribution (discharging)')
plt.bar(n,g,(2*l/a)*(0.95),label='measured number of errors') #bar graph with width of bars equal to horizontal resolution of x axis. can be any value
plt.plot(np.linspace(-l,l,1000),gfunc(np.linspace(-l,l,1000),*gpopt),'g-',label='gaussian fit')
plt.xlabel('error in volts')
plt.ylabel('number of errors')
plt.legend()


#plotting the three subplots of error at different parts of data


plt.figure(2)
plt.bar(n,g1,(2*l/a)*(0.95),label='number of errors')
plt.title('At the beginning (discharging)')
plt.plot(np.linspace(-l,l,1000),gfunc(np.linspace(-l,l,1000),*g1popt),'g-',label='gaussian fit')
plt.xlabel('error in volts')
plt.ylabel('number of errors')
plt.legend()

plt.figure(3)
plt.bar(n,g2,(2*l/a)*(0.95),label='number of errors')
plt.title('in between (discharging)')
plt.plot(np.linspace(-l,l,1000),gfunc(np.linspace(-l,l,1000),*g2popt),'g-',label='gaussian fit')
plt.xlabel('error in volts')
plt.ylabel('number of errors')
plt.legend()

plt.figure(4)
plt.bar(n,g3,(2*l/a)*(0.95),label='number of errors')
plt.title('At the end (discharging)')
plt.plot(np.linspace(-l,l,1000),gfunc(np.linspace(-l,l,1000),*g3popt),'g-',label='gaussian fit')
plt.xlabel('error in volts')
plt.ylabel('number of errors')
plt.legend()



#display all the graph windows 
plt.show()
	



