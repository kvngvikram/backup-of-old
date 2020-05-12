set terminal qt 256
flag = 0
bind all t "flag=1"
while(flag==0) { 
        p cos(x)
        pause 0.1
}
p sin(x)
pause 1
