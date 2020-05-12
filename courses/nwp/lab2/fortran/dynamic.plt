set terminal x11 256
set yrange [-1:1]
set autoscale x
flag = 0
bind all t "flag=1"
while(flag==0) { 
        plot="./temp.dat"
        p plot with lines
        pause 0.01665
}


