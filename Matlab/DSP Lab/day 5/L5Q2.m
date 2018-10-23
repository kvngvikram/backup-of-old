clear
clc 
% x = 2cos(2000pit)+5cos(500pit)
%fs1 = 500 
%fs2 = 2000
%fs3 = 4000
% t = [0 , 8)

%a 
%{
CTFT of x is delta functions as frequencies -1000, -250, 250, and 1000 with
magnitudes of 1, 2.5, 2.5 and 1 respectively
%}

%b 
sf1 = 500;
st1 = 1/sf1; 
t1 = 0 : st1 : .008 - st1;
n1 = 0:numel(t1)-1;
x1 = 2*cos(2000*pi*t1)+5*cos(500*pi*t1);

sf2 = 2000;
st2 = 1/sf2; 
t2 = 0 : st2 : .008 - st2;
n2 = 0:numel(t2)-1;
x2 = 2*cos(2000*pi*t2)+5*cos(500*pi*t2);

sf3 = 4000;
st3 = 1/sf3; 
t3 = 0 : st3 : .008 - st3;
n3 = 0:numel(t3)-1;
x3 = 2*cos(2000*pi*t3)+5*cos(500*pi*t3);

% Computing the DFT of three signals
X1 = fftshift(fft(x1)); % is the N point DFT of x1[n]
X2 = fftshift(fft(x2)); % is the N point DFT of x1[n]
X3 = fftshift(fft(x3)); % is the N point DFT of x1[n]

w1 = -sf1/2+sf1/numel(x1):sf1/numel(x1) : sf1/2;
w2 = -sf2/2+sf2/numel(x2):sf2/numel(x2) : sf2/2;
w3 = -sf3/2+sf3/numel(x3):sf3/numel(x3) : sf3/2;

% plotting 
subplot(3,3,1)
stem(t1,x1)
title('First sampled signal')
xlabel('---> Time')
ylabel('---> Amplitude')

subplot(3,3,2)
stem(t2,x2)
title('Second sampled signal')
xlabel('---> Time')
ylabel('---> Amplitude')

subplot(3,3,3)
stem(t3,x3)
title('Third sampled signal')
xlabel('---> Time')
ylabel('---> Amplitude')

subplot(3,3,4)
stem(w1,abs(X1))
title('DFT of first signal')
xlabel('---> Frequency')
ylabel('---> Absolute amplitude')

subplot(3,3,5)
stem(w2,abs(X2))
title('DFT of second signal')
xlabel('---> Frequency')
ylabel('---> Absolute amplitude')

subplot(3,3,6)
stem(w3,abs(X3))
title('DFT of third signal')
xlabel('---> Frequency')
ylabel('---> Absolute amplitude')

subplot(3,3,7)
stem(w1,abs(X1)/numel(w1))
title('Magnitude corrected DFT of first signal')
xlabel('---> Frequency')
ylabel('---> Absolute amplitude')

subplot(3,3,8)
stem(w2,abs(X2)/numel(w2))
title('Magnitude corrected DFT of second signal')
xlabel('---> Frequency')
ylabel('---> Absolute amplitude')

subplot(3,3,9)
stem(w3,abs(X3)/numel(w3))
title('Magnitude corrected DFT of third signal')
xlabel('---> Frequency')
ylabel('---> Absolute amplitude')

%{
Magnitude of the DFT and CTFT are different because CTFT there is a dw 
in integration but it is not present in DFT. So Magnitude of DFT will be
higher. To normalise it to CTFT it should be divided by N i.e. number of
elements because we have N additions in DFT computation.

Interpolation of original signal is possible only if sampling frequency is
greater than 2000 or else information will be lost due to aliasing so
signal cannot be interpolated from first signal, can be partially
interpolated from second signal and can be completely interpolated without
loss of any information by third signal.
%}

