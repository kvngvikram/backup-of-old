clear;


tol = 10.^-4;  %tol is a converge tolerance

%initial guess or values
x0= [1000;0];

iter= 0; %iterations
xnew =[100;100];
%while norm(xnew -x0) > tol
while iter < 20
    
    iter= iter + 1;
    
    x1 = x0(1);
    x2 = x0(2);
    
    %Defining the functions for c,s and q.
    f = x1^2 + x2^2 -2;
    g = x2 - x1 ;
 
    
    %Partial derivatives in terms of c,s and q.
    dfdx1 = 2*x1;
    dfdx2 = 2*x2 ; 
    
    dgdx1 = -1 ;
    dgdx2 =  1 ;
    %Jacobian matrix 
    J = [dfdx1 dfdx2 ; dgdx1 dgdx2 ];
    
    % Applying the Newton-Raphson method
    %xnew = x0 - J\[f;g;h];
    %x0 = x0 - J\[f;g;h];
    x0 = x0 - J\[f;g];
    disp(J\[f;g])
    disp(sprintf('iter=%6.15f,  x1=%6.15f,  x2=%6.15f', iter,x0)); 
    
end