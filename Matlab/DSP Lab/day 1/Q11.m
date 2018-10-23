A = [2 7 9 7 ; 3 1 5 6 ; 8 1 2 5]

%a
a = A' % transpose

%b
b = A(:,[1 4]) %1st and 4th columns

%c
c = A([2 3],[3 1]) % elements 2,2 ;2,3 ;3,3 ;3,1

%d
d = reshape(A,2,6) % arrangng into 2 x 6 matrix column-wise

%e
e = flipud(A) % flips columns with mirrors

%f
f = fliplr(A) % flips rows

%g
g = [A ; A(end,:)]

%h
h = A(1:3,:) % entire matrix

%i
i = [A ; A(1:2,:)] % repeatition of first two columns

%j
j = sum(A) % sum of each column

%k
k = sum(A')% sum of each row

%l
l = sum(A,2)

%m
m = [ [ A ; sum(A) ] [ sum(A,2) ; sum(A(:)) ] ]