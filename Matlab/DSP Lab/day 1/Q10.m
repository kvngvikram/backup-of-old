x = [1 4 8]
y = [2 1 5]
A = [3 1 6 ; 5 2 7]

%a
a  = x + y  %works

%b
b =  x + A  % matrix dimension not matching

%c
c  = x' + y % matrix dimension not matching

%d 
d  = A - [x' y'] % matrix dimension not matching

%e
e  =  [x ; y'] % matrix dimension not matching

%f
f  = [x ; y] % works

%g
g = A - 3 % works