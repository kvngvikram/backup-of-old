pause 0.0001
set terminal qt 1 
p cos(x)
v = 0
bind all t "v=1"
if(v==0) reread
if(v==1) p sin(x) 
