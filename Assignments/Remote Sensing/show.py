import numpy as np
import matplotlib.pyplot as plt
from PIL import Image

b1 = Image.open('band1.TIF')
b2 = Image.open('band2.TIF')
b3 = Image.open('band3.TIF')
b4 = Image.open('band4.TIF')
b5 = Image.open('band5.TIF')
b6 = Image.open('band6.TIF')
b7 = Image.open('band7.TIF')


a1 = np.asarray(b1,dtype=float)
a2 = np.asarray(b2,dtype=float)
a3 = np.asarray(b3,dtype=float)
a4 = np.asarray(b4,dtype=float)
a5 = np.asarray(b5,dtype=float)
a6 = np.asarray(b6,dtype=float)
a7 = np.asarray(b7,dtype=float)




b = a1 
g = a2
r = a3

rgb = (r+g+b)/3

plt.figure(0)
plt.imshow(rgb,cmap='gray')
plt.show(block=False)



flag = True

while flag : 
	
	string = raw_input('\n\nGive the name of set	: ')
	x1 = input('\nType the first x value	: ')
	x2 = input('\nType the second x value 	: ')
	y1 = input('\nType the first y value	: ')
	y2 = input('\nType the second y value	: ')
	
	if x1>x2 : 
		x1,x2 = x2,x1
	if y1>y2 : 
		y1,y2 = y2,y1
	
	s = np.array([  np.average(a1[x1:x2,y1:y2]) ,  np.average(a2[x1:x2,y1:y2]) ,  np.average(a3[x1:x2,y1:y2]) ,  np.average(a4[x1:x2,y1:y2]) ,  np.average(a5[x1:x2,y1:y2]) ,  np.average(a6[x1:x2,y1:y2]) ,  np.average(a7[x1:x2,y1:y2])   ])
	
	plt.figure(1)
	plt.plot(s,label = string )
	plt.legend()
	plt.show(block = False) 

	flag = bool(input('Do you want to do it again ?  1/0		: '))




print '\n\n\n\t\t\tBye then\t\t\n\n\n'



plt.show() 
