clear;

%values of parameters
k = 0.103; 
p = 3.4;
r = 32.2; 

tol = 10.^-15;  %tol is a converge tolerance

%initial guess or values
x1 = 1000; 
x2 = 0.5; 
x3 = 6.5; 

x0= [x1;x2;x3];

xold = x0 - tol*10

iter= 0; %iterations

while norm(x0 - xold) > tol
%while iter < 20000
    
    iter= iter + 1;
    xold = x0; 
    
    x1 = x0(1);
    x2 = x0(2);
    x3 = x0(3);
    
    %Defining the functions for c,s and q.
    f = 2*x1 + x1*x3*(1-k) + x1*x2*x3*(k-1) -2*k*x1*x3^2 + k*x1*x2*x3^2 -k*x3 +1;
    g = x1*x2*(1+r) + x1*x2*x3 - x1 -2*x1*x3 - 1; 
    h = x1*x2 + x1*x2*x3*(1+p) - 2*x1 - x1*x3 - 1;
    
    %Partial derivatives in terms of c,s and q.
    dfdx1 = 2 + x3*(1-k) + x2*x3*(k-1) - 2*k*x3^2 + k*x2*x3^2;
    dfdx2 = x1*x3*(k-1) + k*x1*x3^2;
    dfdx3 = x1*(1-k) + x1*x2*(k-1) - 4*k*x1*x3 + 2*k*x1*x2*x3 - k; 
    
    dgdx1 = x2*(1+r) + x2*x3 - 1 - 2*x3;
    dgdx2 = x1*(1+r) + x1*x3;
    dgdx3 = x1*x2 - 2*x1;
    
    dhdx1 = x2 + x2*x3*(1+p) - 2 - x3;
    dhdx2 = x1 + x1*x3*(1+p);
    dhdx3 = x1*x2*(1+p) - x1;
    
    %Jacobian matrix 
    J = [dfdx1 dfdx2 dfdx3; dgdx1 dgdx2 dgdx3; dhdx1 dhdx2 dhdx3];
    
    % Applying the Newton-Raphson method
    %xnew = x0 - J\[f;g;h];
    %x0 = x0 - J\[f;g;h];
    x0 = x0 - J\[f;g;h];
    
    %disp(J\[f;g;h])
    disp(sprintf('iter=%6.15f,  x1=%6.15f,  x2=%6.15f, x3=%6.15f', iter,x0)); 
    
end