clear
clc
% range of n
n = -10 : 10 ; 
% defining the signals
causal = cos(n).*double(n>=0 & n<50);
noncausal = exp(n).*double(n<3 & n>-10);
% plotting 
figure()

subplot(1,2,1)
stem(n,noncausal)
title('Non Causal signal')
xlabel('n')
ylabel('Amplitude')

subplot(1,2,2)
stem(n,causal)
title('Causal signal')
xlabel('n')
ylabel('Amplitude')
