import numpy as np 
import random
import cv2 


def sp_noise(image,prob,low_value,high_value):   # function to add salt and pepper noise to image 

    output = np.zeros(image.shape, np.uint8)
    thres = 1 - prob

    for i in range(image.shape[0]):
        for j in range(image.shape[1]):
            rnd = random.random()
            if rnd < prob:
                output[i][j] = low_value
            elif rnd > thres:
                output[i][j] = high_value
            else:
                output[i][j] = image[i][j]

    return output


image = cv2.imread('original.png',0)
noise_image = sp_noise(image,0.05,5,250)
cv2.imwrite('noise_image.png',noise_image)


