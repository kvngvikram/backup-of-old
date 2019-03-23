kernel_size =  4        # n in the n*n kernel

kernel_size = kernel_size + ( 1 - kernel_size % 2 )     # kernel size should be odd 

print(kernel_size)
offset = ( kernel_size - 1)/ 2 

import numpy as np
import cv2 
import matplotlib.pyplot as plt

ni = cv2.imread('noise_image.png',0)
ni = np.asarray(ni,dtype=float)
avg = ni * 0 
var = ni * 0

dummyshape = [ 7 , 8 ]
for i in np.asarray( range( dummyshape[0] - 2 * offset ) ) + offset :
    for j in np.asarray( range( dummyshape[1] - 2 * offset ) ) + offset :
        
        # calculating the local average of kernal
        avg[i][j] = ni[ i-offset : i+offset+1 , j-offset : j+offset+1 ].mean()
        var[i][j] = ni[ i-offset : i+offset+1 , j-offset : j+offset+1 ].var()
        
print(avg[0:10,0:10])
print(var[0:10,0:15])
print(ni[0:10,0:10])

plt.imshow(ni)
#plt.show()
