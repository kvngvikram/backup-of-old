inputname = 'torch.jpg'
outputname = 'torch.csv'
x1 = 1
y1 = 780
x2 = 2969
y2 = 880


# x = [1,2969]
if x1>x2 : 
	d = x1
	x1 = x2 
	x2 = d 

if y1>y2 : 
	d = y1
	y1 = y2
	y2 = d





from PIL import Image
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import numpy as np 

img = Image.open(inputname)
img.load()
im = np.asarray(img)
im = im[:,:,0:3]
plt.figure(0)
plt.imshow(im)
plt.show(block = False)



im = im[(y1-1):y2,(x1-1):x2,:]


plt.figure(1)
plt.imshow(im)
plt.show(block = False)


imR = np.mean(im[:,:,0],axis=0)
imG = np.mean(im[:,:,1],axis=0)
imB = np.mean(im[:,:,2],axis=0)



im = np.mean(im,axis = (0,2))


np.savetxt(outputname,im,delimiter=',')

plt.figure(2)
plt.plot(im)




plt.show()
