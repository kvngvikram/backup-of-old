# This code is for generating particles in the form of .ION file 
# This will generate particles with source position as a circular disk and uniformly distributed

radius = 30 
z = 0.5       		# mm    
m = 1		 	# mass in amu
q = 1.6021762e-19 	# charge in coulombs
az = -90	 	# azimuth angle in deg 
el = 0 			# elevation angle in deg 
TOB = 0 		# Time of Birth in usec

CWF = 0 		# unknown variable (need more understanding)
Color = 3   		# 3 is for blue !! 

N = 1000 		# number of particles with one specific KE 


KE = 10			# kinetic energy in eV
ke = KE 

import random
import numpy as np

myfile = open("particles.ion","w")

#myfile.write("------ Begin Next Fly'm ------\t\t\t\n")


for n in range(N):
	x,y = random.uniform(-radius,radius),random.uniform(-radius,radius)
	
	while x**2+y**2 > radius**2:
		x,y = random.uniform(-radius,radius),random.uniform(-radius,radius)
	
	myfile.write(" %e,%e,%e,%e,%e,%e,%e,%e,%e,%e,%d\n"%(TOB,m,q,x,y,z,az,el,ke,CWF,Color))
	


myfile.close()



