import numpy as np
import matplotlib.pyplot as plt 

ro = 1.21
ro_cp = 1231    # This is product of density and specific heat Cp

data = np.genfromtxt('data.txt')

u,v,w,T= data[:,6],data[:,7],data[:,8],data[:,9]

time = np.linspace(1,np.size(T),np.size(T))

um = np.mean(u) 
vm = np.mean(v)
wm = np.mean(w)
Tm = np.mean(T)

print("\n\n")
print("U mean is " , um)
print("V mean is " , vm)
print("W mean is " , wm)
print("T mean is " , Tm)
print("\n\n")


up = u - um
vp = v - vm
wp = w - wm
Tp = T - Tm

plt.figure(0)
plt.subplot(221)
plt.plot(time,u,'b')
plt.plot(time,time*0+um,'r')
plt.title("U")
plt.subplot(222)
plt.plot(time,v,'b')
plt.plot(time,time*0+vm,'r')
plt.title("V")
plt.subplot(223)
plt.plot(time,w,'b')
plt.plot(time,time*0+wm,'r')
plt.title("W")
plt.subplot(224)
plt.plot(time,T,'b')
plt.plot(time,time*0+Tm,'r')
plt.title("T")

plt.show(block=False)

plt.figure(1)
plt.subplot(221)
plt.plot(up)
plt.title("U prime")
plt.subplot(222)
plt.plot(vp)
plt.title("V prime")
plt.subplot(223)
plt.plot(wp)
plt.title("W prime")
plt.subplot(224)
plt.plot(Tp)
plt.title("T prime")

plt.show(block=False)

e = 0.5*(np.mean(up**2) + np.mean(vp**2) + np.mean(wp**2))
print("Turbulent kinetic energy is " , e)

momentum_flux = ro*( np.mean(up*wp)**2 + np.mean(vp*wp)**2 )**0.5
print("Momentum flux is ",momentum_flux)

sensible_heat_flux = ro_cp*np.mean(wp*Tp)
print("Sensible heat flux is ",sensible_heat_flux)

print("\n\n")
print("Mean of U prime is" , np.mean(up))
print("Mean of V prime is" , np.mean(vp))
print("Mean of W prime is" , np.mean(wp))
print("Mean of T prime is" , np.mean(Tp))

print("\n\n")

plt.show()
