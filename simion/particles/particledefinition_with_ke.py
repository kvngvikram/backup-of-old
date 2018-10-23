# This code is for generating particles in the form of .ION file 
# This will generate particles with source position as a circular disk and uniformly distributed

radius = 30 
z = 0.5       		# mm    
m = 1		 	# mass in amu
q = 1            	# charge in e (not coulombs)
az = -90	 	# azimuth angle in deg 
el = 0 			# elevation angle in deg 
TOB = 0 		# Time of Birth in usec

CWF = 0 		# unknown variable (need more understanding)
Color = 3   		# 3 is for blue !! 

N = 10 		# number of particles with one specific KE 


KEmax = 10			# kinetic energy max in eV
KEdim = 10             # number of intervels of KE from 0 to KE 


import random
import numpy as np

KE = np.linspace(0,KEmax,KEdim)


myfile = open("particles.ion","w")
logfile = open("particleinfo.csv","w")

for ke in KE :  
    for n in range(N):
        x,y = random.uniform(-radius,radius),random.uniform(-radius,radius)
        while x**2+y**2 > radius**2:
            x,y = random.uniform(-radius,radius),random.uniform(-radius,radius)
	
        myfile.write(" %e,%e,%e,%e,%e,%e,%e,%e,%e,%e,%d\n"%(TOB,m,q,x,y,z,az,el,ke,CWF,Color))
	logfile.write("%d\t%e\n"%((n+1),ke))


myfile.close()
logfile.close()


