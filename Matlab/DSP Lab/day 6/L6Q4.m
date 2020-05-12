%%
clear;clc;
%%
% Give signal x[n] and atleast the first start point if lazy
% If not code is smart enough to figure out on its own 
x = [5 5 5 4 4 4 3 2 1    ]; % signal x[n]
n = [-1 0 1 2 ]; % values of n corresponding to x[n]

% matching the array sizes of x[n] and n
if numel(x)~=numel(n)
    if numel(x)<numel(n)
        x = [x zeros(1,(numel(n)-numel(x)))];
    else
        n = [n [n(numel(n))+1:n(numel(n))+(numel(x)-numel(n))]];
    end
end

syms z 
syms f(z) 
f = z*0; 

for i = 1:numel(x)
    f = f + x(i)*z^(-n(i));
end
f = simplify(f)
%%
%DTFT x axis 
wresol = 0.01;
w = 0:wresol:4*pi;
c = exp(1j.*w);

myfunc = matlabFunction(f,'vars',z)

for i = 1:numel(c)

        p(i) = myfunc(c(i));
end
%%
% plotting the magnitude and phase
subplot(2,1,1)
plot(w,abs(p))
title('Magnitude of DTFT from z transform')
xlabel('---> w in radians from 0 to 4pi ')
ylabel('---> Magnitude of DTFT')
subplot(2,1,2)
plot(w,phase(p)*180/pi)
title('Phase of DTFT from z transform')
xlabel('---> w in radians from 0 to 4pi')
ylabel('---> Phase of DTFT')


%%
%{
The obtained DTFT is having a periodicity of 2pi
%}