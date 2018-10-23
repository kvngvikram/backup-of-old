import cv2

#videopath = raw_input('\n\ngive the path of the video along with its name :	')
#vidcap = cv2.VideoCapture(videopath)
#savepath = raw_input('\n\ngive the path to the folder to save the photos :	')
#countrate = input('\n\nenter the count rate :	')
#name = raw_input('\n\nEnter the name of the photos created (<name><photo number>.<type>) :	')
#pictype = raw_input('\n\nEnter the photo type (<name><photo number>.<type>) :	')
#dot = '.'


vidcap = cv2.VideoCapture('/home/happy/bottle.mp4')
countrate = 1


success,image = vidcap.read() # success in a bool and image is actual image
print success
count = 0
totalcount = 0
while success :
	success,image = vidcap.read()	
	count += 1
	#print count
	if success and count == countrate:
		
		cv2.imwrite('/home/happy/data/pos%d.png' % totalcount,image)		
		#cv2.imwrite(savepath+name+str(totalcount)+dot+pictype,image)		

		totalcount +=1
		print 'Image read : %d' % totalcount		
		count = 0 	

