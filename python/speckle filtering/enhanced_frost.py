# Enhanced Frost filter 
# ref : https://www.pcigeomatics.com/geomatica-help/concepts/orthoengine_c/Chapter_823.html 

kernel_size =  5        # n in the n*n kernel
D = 1                   # Damping factor
no_of_looks = 1 

kernel_size = kernel_size + ( 1 - kernel_size % 2 )     # kernel size should be odd 

print('\n\tkernel size is ',kernel_size)
offset = int(( kernel_size - 1)/ 2) 

import numpy as np
import cv2 
import matplotlib.pyplot as plt

ni = cv2.imread('noise_image.png',0)
ni = np.asarray(ni,dtype=float)
ni = np.pad(ni,((offset,offset),(offset,offset)),'constant',constant_values=0.0)

oi = cv2.imread('original.png',0)
oi = np.asarray(oi,dtype=float)
oi = np.pad(oi,((offset,offset),(offset,offset)),'constant',constant_values=0.0)

# matrix S 
T = np.zeros((kernel_size,kernel_size))
for i in range(T.shape[0]):
    for j in range(T.shape[1]):
        T[i][j] = ((i-offset)**2+(j-offset)**2)**0.5    # each element is distance from center

R = ni* 0     # despeckled image same size of noisy image

Cmax = (1.0+2.0/no_of_looks)**0.5
Cu = (1.0/no_of_looks)**0.5

for i in np.asarray( range( ni.shape[0] - 2 * offset ) ) + offset :
    for j in np.asarray( range( ni.shape[1] - 2 * offset ) ) + offset :
        
        # calculating the local average of kernal
        Im = ni[ i-offset : i+offset+1 , j-offset : j+offset+1 ].mean()
        S = ni[ i-offset : i+offset+1 , j-offset : j+offset+1 ].var()**0.5
        Ic = ni[i][j]

        Ci = S/Im
        Ci = np.nan_to_num(Ci)
        
        A = D*(Ci-Cu)/(Cmax-Ci)
        A = np.nan_to_num(A)

        M = np.exp(-A*T)
        M = np.nan_to_num(M)
        
        Rf = np.sum(M*ni[ i-offset : i+offset+1 , j-offset : j+offset+1 ])/np.sum(M)
        Rf = np.nan_to_num(Rf)

        R[i][j] = Im * float( Ci <= Cu ) + Ic * float( Ci >= Cmax ) + Rf * float( Cu<Ci and Ci<Cmax )  

        

dsi = R 

plt.figure(1)
plt.imshow(ni,cmap='gray')
plt.title('Noisy image')
plt.figure(2)
plt.imshow(dsi,cmap='gray')
plt.title('Filtered image | kernel size: '+str(kernel_size))

plt.figure(3)

plt.subplot(311)
hist , temp = np.histogram(oi,bins=256,range=(0,255))
plt.plot(np.linspace(0,255,256),hist)
plt.title('Original image wihtout noise')

plt.subplot(312)
hist , temp = np.histogram(ni,bins=256,range=(0,255))
plt.plot(np.linspace(0,255,256),hist)
plt.title('Noisy image')

plt.subplot(313)
hist , temp = np.histogram(dsi,bins=256,range=(0,255))
plt.plot(np.linspace(0,255,256),hist)
plt.title('filtered image histogram')

plt.show()
