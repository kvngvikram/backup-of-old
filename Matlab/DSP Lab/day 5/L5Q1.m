clear
clc 
% x = 2cos(2000pit)
%sf = 16000 
% t = [0 , 8) 

sf = 16000;
st = 1/sf; 
t = 0 : st : .008 - st;
n = 0:numel(t)-1;
x = 2*cos(2000*pi*t);

% plotting the original sequence
subplot(2,1,1)
stem(t,x)
title('Plotting the actual signal')
xlabel('---> time')
ylabel('---> x[n]')

w = -pi+2*pi/numel(x):2*pi/numel(x) : pi;


%a 
% N point DFT of x[n] 
X = fft(x); % is the N point DFT of x[n]


%b 
%{
CTFT of a periodic signal 2cos(1000*2pit) is delta functions at w = -1000
and w = 1000 both of magnitude 1
%}

%c,d
%{
CTFT plot is continuous but DFT plot is discreet and periodic.
Frequency axis of the DFT should be set to actual frequency and range
should be changed to -pi to pi from 0 to pi using fftshift()
Magnitude of the peaks in DFT plot should be corrected by dividing it with
N(number of elements) since in CTFT there is a dw in integration but it is not present in DFT.
DFT looks like frequency sampled CTFT as in actual frequency axis DFT and
CTFT are same for -fs/2 to fs/2 and the DFT repeats at every fs.
%}
subplot(2,1,2)
% to plot in actual frequency w is multiplied with sample freq and divided
% by 2pi
stem(w*sf/(2*pi),abs(fftshift(X))/numel(X))
title('DFT of sampled signal')
xlabel('---> k')
ylabel('---> |x[k]|')





