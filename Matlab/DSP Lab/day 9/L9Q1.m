%% Bilnear transform 

fs = @(z,T) (2/T)*((1-1./z)/(1+1./z));
fz = @(s,T) (1+s*T/2)/(1-s*T/2);

[x,y] = meshgrid([-3:3],[-3:3]);
y = -y; 

s = x + j*y;

q = 
surf(x,y,(double(real(s)>0).*real(s)))
