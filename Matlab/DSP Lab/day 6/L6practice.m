%%
clear;clc;
%%
%Give the signal
x = [1 2 3 4];
n = [-1 0 1 2 ];

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
