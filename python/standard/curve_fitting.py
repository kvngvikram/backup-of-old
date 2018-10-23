import numpy as np
import matplotlib.pyplot as plt 
from scipy.optimize import curve_fit 

def func(x , a , b , c , d):
	return a*np.sin(b*x+c)+d


x_data = np.linspace(-3,3,101)
y = func(x_data,1,2,3,4)

y_noise = 0.2*np.random.normal(size=np.size(x_data)) 

y_data = y + y_noise 


popt, pcov = curve_fit(func, x_data , y_data , bounds=([0,1,2,3],[2,3,4,5]))

plt.plot(x_data, func(x_data, *popt),'g--',label='fit with bounds')
plt.plot(x_data, y_data , 'p' , label='data points')
plt.xlabel('x')
plt.ylabel('y')
plt.legend()
plt.show()

print ( popt )
