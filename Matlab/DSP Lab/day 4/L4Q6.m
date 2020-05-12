clear;
clc;

x = [ 0 1 2 3 4 ] % x1 
h = [ 4 5 3 ]   % x2 
ax = 0      % starting point of x1 
ah = 0      % starting point of x2 

% selecting the final start point 
a = ax+ah; 

% a) manually calculating convolution

m = length(x);
n = length(h);
X = [x,zeros(1,n)];
H = [h,zeros(1,m)];

% number of terms after convolution n + m - 1
for i = 1:m+n-1
    Y(i)=0; % defining the i'th term 0 initially
    for j = 1:m % for all the terms in x
        if(i-j+1>0) % but not the terms which are not overlapped
            Y(i) = Y(i) + X(j)*H(i-j+1); % summation to Y and H is flipped
        end
    end
end

% defining the x axis for the the convolution solution
x1 = a:a+numel(Y)-1;

% plotting 
subplot(2,1,1)
stem(x1,Y,'g')
ylabel('Convolution sum')
xlabel('---> n')
title('Convolution of two signals') 

% b) second part of solution

% convolution using fft() and ifft()
subplot(2,1,2)
stem([x1 0],ifft(fft(X).*fft(H)),'r')
ylabel('Convolution sum')
xlabel('---> n')
title('Convolution using ifft() and fft()') 

%Inference:
% In manual convolution the length of output is n+m-1
% Using fft and ifft length of convolution is n+m
% where n is length of x and m is length of h