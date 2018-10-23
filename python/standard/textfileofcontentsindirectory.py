# this code stores the names of all the files and folders in a directory in a .txt file


from os import walk 

myfile = open("/home/happy/negative/bg.txt","w")
path = '/home/happy/negative/'

f = []
for (directorypath,directoryname,filename) in walk('/home/happy/negative/'):
	f.extend(filename)

for i in f: 
	myfile.write(i+'\n')

