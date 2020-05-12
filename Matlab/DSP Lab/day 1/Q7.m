% defining x 
% to get non choppy graph steps should be small enough
x=[0.01:0.00001:0.1];

%plotting
figure()
hold()
title('x vs sin(1/x)')
plot(x,sin(1./x))
xlabel('x')
ylabel('sin(1/x)')