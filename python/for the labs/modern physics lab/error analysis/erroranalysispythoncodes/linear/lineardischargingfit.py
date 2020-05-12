import numpy as np
import matplotlib.pyplot as plt 
from scipy.optimize import curve_fit

ydata = np.genfromtxt('linearcharging.csv',delimiter=',')
xdata = np.linspace(0,np.size(ydata)*1.6/1000000000,np.size(ydata))

ydata = np.log(( 2 - ydata )/2) 


m = (np.sum(np.multiply(xdata,ydata))-(np.sum(xdata)*np.sum(ydata))/np.size(xdata))/(np.sum(np.multiply(xdata,xdata))-(np.sum(xdata)*np.sum(xdata))/np.size(xdata))

b = ((np.sum(np.multiply(xdata,xdata))*np.sum(ydata))-(np.sum(xdata)*np.sum(np.multiply(xdata,ydata))))/((np.size(xdata)*np.sum(np.multiply(xdata,xdata)))-(np.sum(xdata)*np.sum(xdata)))

print (m) 
print (b) 

y = m*xdata+b # values of y obtained by least square method fitting. 


# plotting
plt.figure(0)
plt.title('Plotting natural log of Capacitor Voltage for discharging')
plt.plot(xdata,ydata,'.',markersize=0.5)
plt.plot(xdata,y,'g-',label='linear fit curve')
plt.xlabel('time in seconds')
plt.ylabel('Voltage across capacitor')
plt.legend()
#plt.show() 

#now checking if errors from the data to fitted curve follow normal distribution
number_of_bars = 30   #number of bars (in bar graph) in the normal distrubution curve 
error_range = 10     #range of errors i.e. from (-error_range , +error_range)

startpoint = 0 
endpoint = np.size(xdata)
startpoint1 = 0
endpoint1 = 1000
startpoint2 = 2000
endpoint2 = 3000
startpoint3 = 4000
endpoint3 = 5000

a= number_of_bars  #its a lenthy name
l=error_range

#defining the x,y axis variables in error graph
n = np.linspace(-l,l,a) #units: voltage

#g is number of data points having error of n (on x axis), assigned zero initially will be counted soon
#this is for all the data points
g = np.zeros(a)         #units: no unitsnumber of data points having error of n (on x axis), assigned zero initially

g1 = np.linspace(-l,l,a)
g2 = np.linspace(-l,l,a)
g3 = np.linspace(-l,l,a)


#error or deviation of each data point from the fitted value
e = y - ydata 


#counting values of g
i = startpoint #starting from the 0th element or first data point
while i<endpoint: #till the last datapoint
	
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



i = startpoint1 
while i<endpoint1: 
	h = int(np.around(((a/2)*e[i])/l)+(a/2)-1) 	
	g1[h] = g1[h] + 1 #corresponding g is added with one
	i = i+1		#repeating this process for all the data points



i = startpoint2 
while i<endpoint2: 
	h = int(np.around(((a/2)*e[i])/l)+(a/2)-1) 	
	g2[h] = g2[h] + 1 #corresponding g is added with one
	i = i+1		#repeating this process for all the data points



i = startpoint3
while i<endpoint3: 
	h = int(np.around(((a/2)*e[i])/l)+(a/2)-1) 	
	g3[h] = g3[h] + 1 #corresponding g is added with one
	i = i+1		#repeating this process for all the data points


#defining a general gaussian function
def gfunc(x,a,b,c,d):
	return a*np.exp(-b*np.square(x-c))+d


#fitting the data of errors into general gaussian function
#upper bounts are decided by the maximum possible value (for a = 1), but these can be any higher value and can be decided by trails
gpopt, gpcov = curve_fit(gfunc,n,g,bounds=([0,0,-0.5,-100],[np.size(y)+1,np.square(0.5*a/l),0.5,100]))#,bounds=([0,0,-0.5,-100],[np.size(y)+1,np.square(0.5*a/l),0.5,100]))

gpopt1, gpcov1 = curve_fit(gfunc,n,g1,bounds=([0,0,-0.5,-100],[np.size(y)+1,np.square(0.5*a/l),0.5,100]))
gpopt2, gpcov2 = curve_fit(gfunc,n,g2,bounds=([0,0,-0.5,-100],[np.size(y)+1,np.square(0.5*a/l),0.5,100]))
gpopt3, gpcov3 = curve_fit(gfunc,n,g3,bounds=([0,0,-0.5,-100],[np.size(y)+1,np.square(0.5*a/l),0.5,100]))



#plotting error curve for all the data
plt.figure(1) #second figure window
plt.title('Normal error distribution')
plt.bar(n,g,(2*l/a)*0.9,label='measured number of errors') #bar graph with width of bars equal to horizontal resolution of x axis. can be any value
plt.plot(np.linspace(-l,l,1000),gfunc(np.linspace(-l,l,1000),*gpopt),'g-',label='gaussian fit')
plt.xlabel('error')
plt.ylabel('number of errors')
plt.legend()


plt.figure(2)
plt.title('In the beginning')
plt.bar(n,g1,(2*l/a)*0.9,label='Number of errors')
plt.plot(np.linspace(-l,l,1000),gfunc(np.linspace(-l,l,1000),*gpopt1),'g-',label='gaussian fit')
plt.xlabel('error')
plt.ylabel('number of errors')
plt.legend()
plt.figure(3)
plt.title('In between')
plt.bar(n,g2,(2*l/a)*0.9,label='Number of errors')
plt.plot(np.linspace(-l,l,1000),gfunc(np.linspace(-l,l,1000),*gpopt2),'g-',label='gaussian fit')
plt.xlabel('error')
plt.ylabel('number of errors')
plt.legend()
plt.figure(4)
plt.title('At the end')
plt.bar(n,g3,(2*l/a)*0.9,label='Number of errors')
plt.plot(np.linspace(-l,l,1000),gfunc(np.linspace(-l,l,1000),*gpopt3),'g-',label='gaussian fit')
plt.xlabel('error')
plt.ylabel('number of errors')
plt.legend()
#display all the graph windows 
plt.show()

