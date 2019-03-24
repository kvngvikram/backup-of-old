x1 = 1200
y1 = 1200
x2 = 6000
y2 = 6000

if x1>x2 : 
	x1,x2 = x2,x1 
if y1>y2 : 
	y1,y2 = y2,y1



import matplotlib.pyplot as plt
import numpy as np
from PIL import Image

b1 = Image.open('band1.TIF')
b2 = Image.open('band2.TIF')
b3 = Image.open('band3.TIF')
b4 = Image.open('band4.TIF')
b5 = Image.open('band5.TIF')
b6 = Image.open('band6.TIF')
b7 = Image.open('band7.TIF')

a1 = np.asarray(b1,dtype = float)
a2 = np.asarray(b2,dtype = float)
a3 = np.asarray(b3,dtype = float)
a4 = np.asarray(b4,dtype = float)
a5 = np.asarray(b5,dtype = float)
a6 = np.asarray(b6,dtype = float)
a7 = np.asarray(b7,dtype = float)


a1 = a1[y1:y2,x1:x2]
a2 = a2[y1:y2,x1:x2]
a3 = a3[y1:y2,x1:x2]
a4 = a4[y1:y2,x1:x2]
a5 = a5[y1:y2,x1:x2]
a6 = a6[y1:y2,x1:x2]
a7 = a7[y1:y2,x1:x2]




print np.size(a1)

#logicals
l1 = a1>0
l2 = a2>0
l3 = a3>0
l4 = a4>0
l5 = a5>0
l6 = a6>0
l7 = a7>0

 
#flag in bool for valid pixels
f = l1*l2*l3*l4*l5*l6*l7

# l is flag for valid pixel but in floating numbers 0 and 1
l = f.astype(float)
# il is reverse flag in float numbers 0 and 1
il = np.invert(f).astype(float)




#ndbi = ((a5-a4)*l)/(a5+a4+il) # non pixel values will have 0 value
#ndvi = ((a4-a3)*l)/(a4+a3+il) # non pixel values will have 0 value 

ebbi = ((a5-a4)*l)/(10*np.sqrt(a5+a6+il)) # non pixel values will have 0 value



u1 = (ebbi>0.1).astype(bool)

mean46 = (a6+a4)/2

u2 = (mean46 > a5).astype(bool)

u3 = (ebbi<0.35).astype(bool)


myu = u1*u2
ebbiu = u1*u3


print 'Urban ratio is ',np.sum(myu).astype(float)/np.sum(f).astype(float)



plt.figure(0)
plt.imshow(ebbi,cmap='gray')
plt.title('ebbi values')
plt.show(block = False)

plt.figure(1)
plt.imshow(myu,cmap='gray')
plt.title('Threshold and comparision')
plt.show(block = False)

plt.figure(5)
plt.imshow(ebbiu,cmap='gray')
plt.title('thresholded from EBBI')
plt.show(block= False)
plt.show(block = False)

plt.show()
