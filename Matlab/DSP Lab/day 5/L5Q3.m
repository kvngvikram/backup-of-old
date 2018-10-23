clear
clc
x = [1 1 1 1]; 
% n = 0 1 2 3

a = [x zeros(1,8-numel(x))];
b = [x zeros(1,16-numel(x))];
c = [x zeros(1,32-numel(x))];
d = [x zeros(1,1024-numel(x))];

sf = 1; 

A = fftshift(fft(a));
B = fftshift(fft(b));
C = fftshift(fft(c));
D = fftshift(fft(d));

subplot(4,1,1)
stem([-sf/2+sf/numel(A):sf/numel(A):sf/2],abs(A))
title('8 point DFT')
ylabel('Amplitude')
xlabel('---> Frequency')
subplot(4,1,2)
stem([-sf/2+sf/numel(B):sf/numel(B):sf/2],abs(B))
xlabel('---> Frequency')
ylabel('Amplitude')
title('16 point DFT')
subplot(4,1,3)
stem([-sf/2+sf/numel(C):sf/numel(C):sf/2],abs(C))
xlabel('---> Frequency')
ylabel('Amplitude')
title('32 point DFT')
subplot(4,1,4)
stem([-sf/2+sf/numel(D):sf/numel(D):sf/2],abs(D))
xlabel('---> Frequency')
ylabel('Amplitude')
title('1024 point DFT')

%%
%{
Inference: The DFT of N points is the frequency sampled CTFT at frequency
sampling rate of Sampling Frequency / N 
As the time increases the number of samples increases but the shape of DFT
will be same. 
%}