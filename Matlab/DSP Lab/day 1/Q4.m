%a
x=2/2*3 
% / has more priority than * 

%b 
x=6-2/5+7^2-1
% ^ has more priority than / 

%c
x=10/2\5-3+2*4
% / has more priority than \, i.e. division in reverse

%d
x=3^2/4
% ^ has more priority than /

%e
x=3^2^2 
% 

%f
x = 2+round(6/9+3*2)/2-3
% round to upper integer if value >0.5
% round to lower integer if value <0.5

%g
x = 2+floor(6/9+3*2)/2-3
% round to lower integer 

%h
x = 2+ceil(6/9+3*2)/2-3
% round to upper integer 