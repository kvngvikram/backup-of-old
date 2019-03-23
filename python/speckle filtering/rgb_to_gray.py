import cv2 
gray = cv2.imread('original_RGB.png',0)
cv2.imwrite('original.png',gray)
