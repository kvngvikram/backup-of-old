% DTFT, IDTFT and convolution

n = -20:20;    % extent of n for the two signals x[n] and h[n]

% defining the signals
x = 1*double(n>=-10 & n<=5);
h = n.*double(n>=0 & n<=10);

dw = 0.001;    % resolution of frequency axis
w = -pi:dw:pi; % DTFT from -pi to pi

% calculating the DTFT of x[n] and h[n] simultaniously
for i = 1:numel(w) % at each point on freq axis
    X(i) = 0;
    H(i) = 0;
    % calculating summation at different n
    for j = 1:numel(n)
        X(i) = X(i) + x(j)*exp(-1i*w(i)*n(j));
        H(i) = H(i) + h(j)*exp(-1i*w(i)*n(j));
    end
end

% convolution in time domain is multiplication in frequency domain
Y = X.*H;

% IDTFT of Y 
for i = 1:numel(n) % at each n
    y(i)=0;
    % calculating the IDTFT integration at all the w
    for j = 1:numel(w)
        y(i) = y(i) + (0.5/pi)*Y(j)*exp(1j*w(j)*n(i))*dw;
        % 0.5/pi is normalisation factor, dw is resolution
    end
end

% plotting the results

% original signal x[n]
subplot(2,2,1)
stem(n,x)
title('Singnal x[n]')
ylabel('---> x[n]')
xlabel('---> n')

% signal h[n]
subplot(2,2,2)
stem(n,h)
title('Signal h[n]')
xlabel('---> n')
ylabel('---> h[n]')

% DTFT of x[n]
subplot(2,2,3)
plot(w,abs(X))
title('Transform X(w)')
xlabel('---> w')
ylabel('---> |X(w)|')

% DTFT of h[n]
subplot(2,2,4)
plot(w,abs(H))
title('Transform H(w)')
xlabel('---> w')
ylabel('---> |H(w)|')

figure()

% convolution using inbuilt function
subplot(2,1,1)
% defining the n (x axis)
length = numel(x)+numel(h)-1; % length of convolved signal
start = n(1) + n(1); % one for x and other for h
n1 = start:start+length-1; % x axis
stem(n1,conv(x,h)) % conv(x,h) is the inbuilt function
title('Convolution using inbuilt function')
xlabel('---> n')
ylabel('---> conv(x,h)')

% plotting calculated convolution
subplot(2,1,2)
stem(n,real(y))
title('Calculated convolution using transforms')
xlabel('---> n')
ylabel('---> IDTFT(DFT(x,h))')

%{
Inference:
conv(x,h) gives array as output with number of elements = n(x)+n(h)-1
While calculating with code the range of n which we work on shoud be
carefully selected (should be big enough range.
%}
