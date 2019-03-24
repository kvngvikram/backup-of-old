# Lee Sigma filter 
# ref : https://www.imageeprocessing.com/2014/08/lee-filter.html

kernel_size =  5        # n in the n*n kernel

kernel_size = kernel_size + ( 1 - kernel_size % 2 )     # kernel size should be odd 

print('\n\tkernel size is ',kernel_size)
offset = int(( kernel_size - 1)/ 2) 

import numpy as np
import cv2 
import matplotlib.pyplot as plt

ni = cv2.imread('noise_image.png',0)
ni = np.asarray(ni,dtype=float)

oi = cv2.imread('original.png',0)
oi = np.asarray(oi,dtype=float)

ni = np.pad(ni,((offset,offset),(offset,offset)),'constant',constant_values=0.0)
oi = np.pad(oi,((offset,offset),(offset,offset)),'constant',constant_values=0.0)

avg = ni * 0 
var = ni * 0
lrvar = oi * 0
w = avg * 0

dummyshape = [ 7 , 8 ]
for i in np.asarray( range( ni.shape[0] - 2 * offset ) ) + offset :
    for j in np.asarray( range( ni.shape[1] - 2 * offset ) ) + offset :
        
        # calculating the local average of kernal
        avg[i][j] = ni[ i-offset : i+offset+1 , j-offset : j+offset+1 ].mean()
        var[i][j] = ni[ i-offset : i+offset+1 , j-offset : j+offset+1 ].var()
        lrvar[i][j] = oi[ i-offset : i+offset+1 , j-offset : j+offset+1 ].var()


ref_var = ni.var()       ########

w = var/(var+ref_var)
dsi = avg + w*(ni-avg)


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
