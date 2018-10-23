import numpy as np 
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit 



data = np.genfromtxt('ideal.csv',delimiter=',')
xdata = data[:,0]
cover = np.zeros((5,np.size(xdata)))
cover[0,:] = data[:,1]
data = np.genfromtxt('1cover.csv',delimiter=',')
cover[1,:] = data[:,1]
data = np.genfromtxt('2cover.csv',delimiter=',')
cover[2,:] = data[:,1]
data = np.genfromtxt('3cover.csv',delimiter=',')
cover[3,:] = data[:,1]
data = np.genfromtxt('4cover.csv',delimiter=',')
cover[4,:] = data[:,1]

plt.figure(0)
plt.subplot(251)
plt.axis([xdata[0],xdata[np.size(xdata)-1],0,np.max(cover[0])])
plt.plot(xdata,cover[0])
plt.title('No sheet(ideal)')
plt.xlabel('Wavelength in nm')
plt.ylabel('Intensity')
plt.subplot(252)
plt.axis([xdata[0],xdata[np.size(xdata)-1],0,np.max(cover[0])])
plt.plot(xdata,cover[1])
plt.title('1 sheet')
plt.xlabel('Wavelength in nm')
plt.subplot(253)
plt.axis([xdata[0],xdata[np.size(xdata)-1],0,np.max(cover[0])])
plt.plot(xdata,cover[2])
plt.title('2 sheet')
plt.xlabel('Wavelength in nm')
plt.subplot(254)
plt.axis([xdata[0],xdata[np.size(xdata)-1],0,np.max(cover[0])])
plt.plot(xdata,cover[3])
plt.title('3 sheet')
plt.xlabel('Wavelength in nm')
plt.subplot(255)
plt.axis([xdata[0],xdata[np.size(xdata)-1],0,np.max(cover[0])])
plt.plot(xdata,cover[4])
plt.title('4 sheet')
plt.xlabel('Wavelength in nm')

integral = np.zeros(5)
dx = xdata[1]-xdata[0]

for i in range(5):
	integral[i]=np.sum(cover[i,:])*dx
ix = np.linspace(0,4,5)

def func(x , a , b ):
	return a*x+b

popt, pcov = curve_fit(func, ix , integral )

print('\n\nValue of slope and intercept of line : ')
print(popt)
print('\n')

plt.subplot(212)
plt.scatter(ix,integral)
plt.plot(ix,func(ix,*popt),color = 'red')
plt.xlabel('Number of transparent sheets')
plt.ylabel('Area of spectrum')
plt.show(block = False)

data = np.genfromtxt('blackstain.csv',delimiter=',')
black = data[:,1]
data = np.genfromtxt('bluestain.csv',delimiter=',')
blue = data[:,1]
data = np.genfromtxt('blackandbluestainstogether.csv',delimiter=',')
blackblue = data[:,1]

ideal = cover[0,:]
plt.figure(1)
plt.subplot(231)
plt.axis([xdata[0],xdata[np.size(xdata)-1],0,np.max(ideal)])
plt.plot(xdata,ideal)
plt.title('No sheet(ideal)')
#plt.xlabel('Wavelength in nm')
plt.ylabel('Intensity')
plt.subplot(232)
plt.axis([xdata[0],xdata[np.size(xdata)-1],0,np.max(ideal)])
plt.plot(xdata,blue)
#plt.xlabel('Wavelength in nm')
plt.title('transparent sheet with blue marker stain')
plt.subplot(233)
plt.axis([xdata[0],xdata[np.size(xdata)-1],0,np.max(ideal)])
plt.plot(xdata,black)
#plt.xlabel('Wavelength in nm')
plt.title('Transparen sheet with black marker stain')
plt.subplot(223)
plt.axis([xdata[0],xdata[np.size(xdata)-1],0,1])
plt.plot(xdata,(ideal-blue)/ideal)
plt.xlabel('Wavelength in nm')
plt.ylabel('Absorption coefficient')
plt.title('Absorption coefficient of Blue marker ink')
plt.subplot(224)
plt.axis([xdata[0],xdata[np.size(xdata)-1],0,1])
plt.plot(xdata,(ideal-black)/ideal)
plt.xlabel('Wavelength in nm')
plt.ylabel('Absorption coefficient')
plt.title('Absorption coefficient of Black marker in')


data = np.genfromtxt('myspectclefromeye.csv',delimiter=',')
eye = data[:,1]

plt.figure(2)
plt.subplot(221)
plt.axis([xdata[0],xdata[np.size(xdata)-1],0,np.max(ideal)])
plt.plot(xdata,ideal)
plt.title('Ideal')
#plt.xlabel('Wavelength in nm')
plt.ylabel('Intensity')
plt.subplot(222)
plt.axis([xdata[0],xdata[np.size(xdata)-1],0,np.max(ideal)])
plt.plot(xdata,eye)
plt.title('Through the glasses')
#plt.xlabel('Wavelength in nm')
plt.ylabel('Intensity')
plt.subplot(212)
plt.axis([xdata[0],xdata[np.size(xdata)-1],0,1])
plt.plot(xdata,(ideal-eye)/ideal)
plt.xlabel('Wavelength in nm')
plt.ylabel('Absorption coefficient')
plt.title('Absorption coefficient of glasses')

plt.show()	

