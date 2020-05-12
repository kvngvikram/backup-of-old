%take inputs from user and define vector
n = input('type number of elements in vector :  ');
n1 = input('type beginning value of vector :  ');
n2 = input('type ending value of vector :  ');
t =[n1:(n2-n1)/(n-1):n2]

%a 
a=log(2+t+t.^2)

%b
b=exp(t).*(1+cos(3*t))