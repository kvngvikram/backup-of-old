import PyGnuplot as gp
import numpy as np

x = np.linspace(-1,1,21)
y = x**2

gp.c('set terminal dumb')
gp.s([x,y])
gp.c('plot sin(x)')
gp.c('plot "tmp.dat"')
