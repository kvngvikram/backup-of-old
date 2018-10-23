




from PA import *


pa = PA(nx = 1000, ny = 1000, nz = 200, field_type = 'electrostatic', symmetry = 'planar', fast_adjustable = 1, enable_points = 1)

pa.point(0,0,0,1,5)





pa.point(1,1,0,1,5)
pa.point(2,1,0,1,5)
pa.point(1,2,0,1,5)
pa.point(2,2,0,1,5)






pa.save('myfile.pa#')
