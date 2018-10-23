clc;
clear;

% define the aks and bks here
ak = [ 1 0.25 0.25 ];
bk = [ 0.7  0 ];

% x is the input signal
n = 0:25;
x = 1*double(n>=5 & n<=15);

% y is output initially 0 
y = 0*x;

% a)

% calculating each term of y which has same number of elements as x
for i = 1:numel(x)
    % calculating y(i)
    % first considering aks
    for j = 1:numel(ak) 
        % elements of y initially zero in all range and before and after the range
        % so elements with index of y < 0 in not required to be added
        if i-j+1>0 
            y(i) = y(i) + ak(j)*x(i-j+1);
        end
    end
    % calculating for bk
    for j = 1:numel(bk)
        if i-j>0 % elements initally are zeros or elements before the y range of y
            y(i) = y(i) + bk(j)*y(i-j);
        end
    end
end


% b 

% filter(a,b,x) is the inbuilt function of matlab which takes aks, bks and
% x[n] and calculates the output signal with same number of elements as x[n]
% fourth aurgument is for the initial conditions of y[n] which is
% considered zero
y1 = filter(ak,bk,x,zeros(1,max(length(ak),length(bk))-1)); 


%plotting te input and output
subplot(3,1,1)
stem(n,x)
title('Input signal x[n]')
xlabel('---> n')
ylabel('---> x[n]')

% plotting calculated output signal
subplot(3,1,2)
stem(n,y)
title('Calculated output signal y[n] for given ak and bk')
xlabel('---> n')
ylabel('---> y[n]')

% plotting output by inbuilt function
subplot(3,1,3)
stem(n,y1)
title('Output of inbuilt function filter(a,b,x)')
xlabel('---> n')
ylabel('---> y[n]') 

