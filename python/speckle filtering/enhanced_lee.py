# Enhanced Lee filter 
# ref : ://www.pcigeomatics.com/geomatica-help/concepts/orthoengine_c/Chapter_825.htmll

kernel_size =  5        # n in the n*n kernel
no_of_looks = 1         
damping_factor = 1

kernel_size = kernel_size + ( 1 - kernel_size % 2 )     # kernel size should be odd 
print('\n\tkernel size is ',kernel_size)    
offset = int(( kernel_size - 1)/ 2)             # offset calculation

import numpy as np
import cv2 
import matplotlib.pyplot as plt

# reading images and converting them into numpy arrays
ni = cv2.imread('noise_image.png',0)
ni = np.asarray(ni,dtype=float)

oi = cv2.imread('original.png',0)
oi = np.asarray(oi,dtype=float)

# Padding with offset on all directions
ni = np.pad(ni,((offset,offset),(offset,offset)),'constant',constant_values=0.0)
oi = np.pad(oi,((offset,offset),(offset,offset)),'constant',constant_values=0.0)

# preparing the required variables with same dimensions as images
avg = ni * 0 
var = ni * 0

ni = ni + np.asarray( ni == 0 )
R = ni*0 

for i in np.asarray( range( ni.shape[0] - 2 * offset ) ) + offset :
    for j in np.asarray( range( ni.shape[1] - 2 * offset ) ) + offset :
        
        # calculating the local average of noisy image
        avg[i][j] = ni[ i-offset : i+offset+1 , j-offset : j+offset+1 ].mean()
        # calculation the local varience of noisy image
        var[i][j] = ni[ i-offset : i+offset+1 , j-offset : j+offset+1 ].var()
'''
        S = var[i][j]**0.5
        Im = avg[i][j] 
        Ic = ni[i][j]
        Ci = np.nan_to_num( S/Im ) 
        Cu = (1.0/float(no_of_looks))**0.5
        Cmax = (1.0+2.0/float(no_of_looks))**0.5
        W = np.exp(-damping_factor*(Ci-Cu)/(Cmax-Ci))
'''
        #R[i][j] = Im * np.asarray( Ci <= Cu ) + Ic * np.asarray( Ci >= Cmax ) + ( Im*W + Ic*(1-W) ) * np.asarray(np.logical_and( Cu<Ci , Ci<Cmax ))  
'''
        if Ci < Cu : 
            R[i][j] = Im
        elif Ci > Cmax : 
            R[i][j] = Ic 
        else : 
            R[i][j] =  Im*W + Ic*(1-W)  
   '''         
######################################################

S = var**0.5
Im = avg 
Ic = ni
Ci = np.nan_to_num( S/Im ) 
Cu = (1.0/float(no_of_looks))**0.5
Cmax = (1.0+2.0/float(no_of_looks))**0.5
W = np.exp(-damping_factor*(Ci-Cu)/(Cmax-Ci))

R = Im * np.asarray( Ci <= Cu ) + Ic * np.asarray( Ci >= Cmax ) + ( Im*W + Ic*(1-W) ) * np.asarray(np.logical_and( Cu<Ci , Ci<Cmax ))  

plt.figure(1)
plt.imshow(ni,cmap='gray')
plt.title('Noisy image')
plt.figure(2)
plt.imshow(R,cmap='gray')
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
hist , temp = np.histogram(R,bins=256,range=(0,255))
plt.plot(np.linspace(0,255,256),hist)
plt.title('filtered image histogram')

plt.show()
