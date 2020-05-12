import numpy as np
import matplotlib.pyplot as plt 

def func(x,c):
    #return c[0]*np.exp(-((x-c[1])/c[2])**2) + c[3] 
    #return c[0]*x**3 + c[1]*x**2 + c[2]*x + c[3]*x*0.5 + c[4]
    #return c[0]*np.exp(c[1]*x)
    #return c[0]*np.exp(c[1]*x) + c[2]
    #return c[0]*np.cos(x*c[1]) + c[2]*np.sin(x*c[3])
    return c[0]*x + c[1]*x**2 + c[2]*x**3 + c[3]


c = np.array([5 , 1 , 10,0.8  ])
sigma = 1.5
max_iteration = 40
initial_c = np.array([4, 1.2 , 5,0.6  ])

print('\n\tInitial vales : \t',initial_c)
#initial_c = initial_c*0
c = np.array(c,dtype=float)
x = np.linspace(-10,10,2*80 + 1)
noise = np.random.normal(0.0,sigma,np.size(x))
y = func(x,c) + noise 

plt.scatter(x,y,s=10,label='data')

c = initial_c.astype(float) 
dc = c*0 + 0.001

def dc_array(dc,i):
    index_array = np.linspace(0,np.size(dc)-1,np.size(dc),dtype = int)
    return dc*(index_array == i).astype(float)

Y = np.asmatrix(y).T
C = np.asmatrix(c).T

i = 0
while i < max_iteration:
    matrix = (func(x,c+dc_array(dc,0))-func(x,c-dc_array(dc,0)))/(2*dc[0])
    matrix = np.nan_to_num(matrix)
    for j in np.linspace(1,np.size(c)-1,np.size(c)-1,dtype=int):
        column = (func(x,c+dc_array(dc,j))-func(x,c-dc_array(dc,j)))/(2*dc[j])
        column = np.nan_to_num(column)
        matrix = np.column_stack((matrix,column))

    X = np.asmatrix(matrix)
    delta_Y = Y - np.asmatrix(func(x,np.asarray(C)[:,0])).T
    XtXwi = (X.T * X).I
    delta_C = XtXwi*X.T*delta_Y
    C += delta_C
# Hey !! no need to uncomment the below line. C and c are connected. 
# They seems to be same, except the one is array and other is matrix
#    c += np.asarray(delta_C)[:,0]
    #Y = Y - X*C
    plt.plot(x,func(x,c))
    i += 1
print('\n\tInitial vales : \t',c)
plt.plot(x,func(x,c),'r',label='Fit')
plt.title('Fitting')
plt.legend()
plt.show()
