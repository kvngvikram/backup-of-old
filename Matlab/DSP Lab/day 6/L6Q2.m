%%
clear;clc;
%%
%Give the zeros and poles
zero = [1+1j 2 3 4 3];
pole = [-1-2j 0 1 1 1 2 ];

% defining a symbolic variable z
syms z 
syms f(z)  % symbolic function
f = z*0+1; % initially assigned zero

% multiplying the terms of zeros in nominator
for i = 1:numel(zero)
    f = f*(z-zero(i)) ;
end
% dividing terms of poles in denominator
for i = 1:numel(pole)
    f = f/(z-pole(i)) ;
end

f = simplify(f) % simplifying the expression 
%% 
%{
Here the zeros and poles of z transforms are given in the form of matlab
vectors. So it can be said that rational z transforms can be represented
using vectors. Here for there is no need for seperate representation of
multiplicities, this can be done by giving corresponding number of similar
values in the vectors itself. 
%}
%%
%{
Here the ordering of zeros and poles does not matter because the expression is being simplified.  
%}
