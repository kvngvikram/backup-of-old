%%
clear;clc;
%%
%Give the zeros and poles
zero = [1  -1 1j  -1j];
pole = [0  1+1j 1-1j -1+1j -1-1j    ];

R = 3; % range of |X(z)| plot from -R to R
res = .05; % resolution of |X(z)| plot

syms z  % defining the symbolic variable z 
syms f(z)  % symbolic function
f = z*0+1; % initially zero 

% multiplying terms of zeros 
for i = 1:numel(zero)
    f = f*(z-zero(i)) ;
end
% dividing terms of poles
for i = 1:numel(pole)
    f = f/(z-pole(i)) ;
end
f = simplify(f) % simplifying 
%%
real = -R:res:R; % real axis 
complex = 1j*real; % complex axis 
c = real+complex'; % complex plane 

% defining the function which will calculate values. 
myfunc = matlabFunction(f,'vars',z)

% p is the matrix that stores the magnitude values 
% caluclating the value of p for each point in the plane
for i = 1:numel(real)
    for j = 1:numel(complex)
        p(i,j) = myfunc(real(i)+complex(j));
        % value of p will be left empty if there is a pole 
    end
end
%%
% surface plotting 
surf(real,complex/1j,abs(p),'LineStyle','none')
title('|X(z)| 3D plot')
xlabel('real axis')
ylabel('complex axis')
zlabel('|X(z)|')

%%
%{
Inference: subs() function takes a lot of time but in the above procedure
the same process can be done with lot lesser time of execution. 

Near zeros the |X(z)| plot will have the value zero and at poles the
magnitude value is infinite. Here in the code it takes the just before
value which is also high. As the multiplicity of zero at a point increases
the magnitude decreases to zero more rapidly and as the multiplicity of
pole at a point increases the magnitude increases to infinity more rapidly.

For the given poles and zeros the ROC |z|>2^(0.5)

For 
2) 
zeros = [2 3 4 ];
poles = [0]; 
ROC is |z|>0 
3)
zeros = [0 1 2]; 
poles = [3];
ROC is |z|>3 or |z|<3 
%}