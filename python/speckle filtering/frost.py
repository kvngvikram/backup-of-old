# Frost filter 
# ref : https://www.imageeprocessing.com/2018/06/frost-filter.html 

kernel_size =  5        # n in the n*n kernel
D = 1                   # Damping factor


kernel_size = kernel_size + ( 1 - kernel_size % 2 )     # kernel size should be odd 

print('\n\tkernel size is ',kernel_size)
offset = int(( kernel_size - 1)/ 2) 

import numpy as np
import cv2 
import matplotlib.pyplot as plt

ni = cv2.imread('noise_image.png',0)
ni = np.asarray(ni,dtype=float)
ni = np.pad(ni,((offset,offset),(offset,offset)),'constant',constant_values=0.0)

# matrix S 
S = np.zeros((kernel_size,kernel_size))
for i in range(S.shape[0]):
    for j in range(S.shape[1]):
        S[i][j] = ((i-offset)**2+(j-offset)**2)**0.5    # each element is distance from center

dsi = ni* 0     # despeckled image same size of noisy image

for i in np.asarray( range( ni.shape[0] - 2 * offset ) ) + offset :
    for j in np.asarray( range( ni.shape[1] - 2 * offset ) ) + offset :
        
        # calculating the local average of kernal
        avg = ni[ i-offset : i+offset+1 , j-offset : j+offset+1 ].mean()
        var = ni[ i-offset : i+offset+1 , j-offset : j+offset+1 ].var()
        
        B = D*var/avg**2
        B = np.nan_to_num(B)    # Changing nan values to 0 

        W = np.exp(-S*B)
        
        dsi[i][j] = np.sum(W*ni[ i-offset : i+offset+1 , j-offset : j+offset+1 ])/np.sum(W)




plt.figure(1)
plt.imshow(ni,cmap='gray')
plt.title('Noisy image')
plt.figure(2)
plt.imshow(dsi,cmap='gray')
plt.title('Filtered image | kernel size: '+str(kernel_size))
plt.show()
