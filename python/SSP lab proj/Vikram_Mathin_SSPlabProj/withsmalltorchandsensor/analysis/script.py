# in lamda = C0 + C1*index + C2*index^2



import numpy as np 
import matplotlib.pyplot as plt



background = np.genfromtxt('background.csv',delimiter=',')
source = np.genfromtxt('source.csv',delimiter=',')
yellow = np.genfromtxt('yellowfilter.csv',delimiter =',')
red = np.genfromtxt('redfilter.csv',delimiter = ',')
green = np.genfromtxt('greenfilter.csv',delimiter=',')
lightgreen = np.genfromtxt('lightgreenfilter.csv',delimiter=',')

index = np.linspace(0,np.size(source)-1,np.size(source))

lamda = index*4/53 + (23326/53)


s = source - background
y = yellow - background
r = red - background 
g = green - background 
lg = lightgreen - background


yf = y/s
gf = g/s
rf = r/s
lgf = lg/s


xaxis1 = (lamda[0])
xaxis2 = (lamda[np.size(lamda)-1])


plt.figure(0)
plt.title('Filter characterstics')

plt.subplot(411)
plt.axis([xaxis1,xaxis2,0,1.5])
plt.plot(lamda,gf)
plt.title('Green filter')
plt.ylabel('Transmittance')

plt.subplot(412)
plt.axis([xaxis1,xaxis2,0,1.5])
plt.plot(lamda,lgf)
plt.title('Light green filter')
plt.ylabel('Transmittance')

plt.subplot(413)
plt.axis([xaxis1,xaxis2,0,1.5])
plt.plot(lamda,yf)
plt.title('Yellow filter')
plt.ylabel('Transmittance')

plt.subplot(414)
plt.axis([xaxis1,xaxis2,0,1.5])
plt.plot(lamda,rf)
plt.title('Red filter')
plt.ylabel('Transmittance')
plt.xlabel('Wavelength in nm')





plt.show()	

