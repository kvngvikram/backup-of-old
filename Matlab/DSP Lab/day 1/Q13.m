x = [4 1 6]
y = [6 2 7]

%a 
a = x>y 

%b
b = y<x 

%c
c = x==y 

%d 
d = x<=y 

%e 
e = y>=x 

%f
f = x|y 

%g 
g = x&y 

%h 
h = x&(~y)

%i
i = (x>y)|(y<x)

%j
j = (x>y)&(y<x)

%k 
k = x'*y

%l
l = x'./y

%m
m = sum(x.*y)

%n
for i = 1:3 
  if x(i)>y(i)
    n(i)= y(i);
  else 
    n(i) = x(i);
   end
  n(i)= 1/n(i);
end 
n

