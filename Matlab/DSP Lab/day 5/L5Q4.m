clear
clc
%% x = 2cos(2000pit), Fs1 = 8000, Fs2 = 16000, Fs3 = 8888, Fs4 = 17776

Fs1 = 8000; 
Fs2 = 16000 ;
Fs3 = 8888; 
Fs4 = 17776; 

xtime = 8; % ms 
ytime = 8; % ms without 8 

st1 = 1/Fs1; 
st2 = 1/Fs2; 
st3 = 1/Fs3; 
st4 = 1/Fs4; 

% Time axis for each signal 
tx1 = 0:st1:xtime/1000 - st1;
tx2 = 0:st2:xtime/1000 - st2;
tx3 = 0:st3:xtime/1000 - st3;
tx4 = 0:st4:xtime/1000 - st4;

ty1 = 0:st1:ytime/1000;
ty2 = 0:st2:ytime/1000;
ty3 = 0:st3:ytime/1000;
ty4 = 0:st4:ytime/1000;
% signals
x1 = 2*cos(2000*pi*tx1);
x2 = 2*cos(2000*pi*tx2);
x3 = 2*cos(2000*pi*tx3);
x4 = 2*cos(2000*pi*tx4);

y1 = 2*cos(2000*pi*ty1);
y2 = 2*cos(2000*pi*ty2);
y3 = 2*cos(2000*pi*ty3);
y4 = 2*cos(2000*pi*ty4); 

X1 = fftshift(fft(x1));
X2 = fftshift(fft(x2));
X3 = fftshift(fft(x3));
X4 = fftshift(fft(x4));
Y1 = fftshift(fft(y1));
Y2 = fftshift(fft(y2));
Y3 = fftshift(fft(y3));
Y4 = fftshift(fft(y4));

subplot(2,4,1)
stem([-Fs1/2+Fs1/numel(X1):Fs1/numel(X1):Fs1/2],abs(X1))
title('DFT of x[n] Fs = 8000')
xlabel('---> Frequency')
ylabel('Amplitude')
subplot(2,4,2)
stem([-Fs2/2+Fs2/numel(X2):Fs2/numel(X2):Fs2/2],abs(X2))
title('DFT of x[n] for Fs = 16000')
xlabel('---> Frequency')
ylabel('Amplitude')
subplot(2,4,3)
stem([-Fs3/2+Fs3/numel(X3):Fs3/numel(X3):Fs3/2],abs(X3))
title('DFT of x[n] for Fs = 8888')
xlabel('---> Frequency')
ylabel('Amplitude')
subplot(2,4,4)
stem([-Fs4/2+Fs4/numel(X4):Fs4/numel(X4):Fs4/2],abs(X4))
title('DFT of x[n] for Fs = 17776')
xlabel('---> Frequency')
ylabel('Amplitude')
subplot(2,4,5)
stem([-Fs1/2+Fs1/numel(Y1):Fs1/numel(Y1):Fs1/2],abs(Y1))
title('DFT of y[n] for Fs = 8000')
xlabel('---> Frequency')
ylabel('Amplitude')
subplot(2,4,6)
stem([-Fs2/2+Fs2/numel(Y2):Fs2/numel(Y2):Fs2/2],abs(Y2))
title('DFT of y[n] for Fs = 16000')
xlabel('---> Frequency')
ylabel('Amplitude')
subplot(2,4,7)
stem([-Fs3/2+Fs3/numel(Y3):Fs3/numel(Y3):Fs3/2],abs(Y3))
title('DFT of y[n] for Fs = 8888')
xlabel('---> Frequency')
ylabel('Amplitude')
subplot(2,4,8)
stem([-Fs4/2+Fs4/numel(Y4):Fs4/numel(Y4):Fs4/2],abs(Y4))
title('DFT of y[n] for Fs = 17776')
xlabel('---> Frequency')
ylabel('Amplitude')
%%
%{
Inference: In x[n] the signal is perfect sine wave but in y[n] due to the
last sample if we extend the sequence periodically the signal will not be a
perfect sine wave. So the DFT of y[n] is not resembling the actual CTFT of
sine wave where as DFT of x[n] is perfectly sampelled CTFT. 
 %}
%%
ztime = 4; % ms 
tz = 0:st1:ztime/1000 - st1;
z = 2*cos(2000*pi*tz);
z = [z zeros(1,(numel(x1)-numel(z)))];
Z = fftshift(fft(z));

figure()
subplot(2,2,1)
stem(tx1,x1)
title('Signal x[n] at Fs = 8000')
xlabel('---> Time (sec)')
ylabel('Amplitude')
subplot(2,2,3)
stem(tx1,z)
title('Signal z[n] at Fs = 8000')
xlabel('-l--> Time (sec)')
ylabel('Amplitude')
subplot(2,2,2)
stem([-Fs1/2+Fs1/numel(X1):Fs1/numel(X1):Fs1/2],abs(X1))
title('DFT of x[n] Fs = 8000')
xlabel('---> Frequency')
ylabel('Amplitude')
subplot(2,2,4)
stem([-Fs1/2+Fs1/numel(Z):Fs1/numel(Z):Fs1/2],abs(Z))
title('DFT of z[n] Fs = 8000')
xlabel('---> Frequency')
ylabel('Amplitude')
%%
%{
Inference: z[n] is same as x[n] but can be considered as multiplied with
value 1 for first half and 0 on the second half. The signal that should be
multiplied with x[n] to obtain z[n] is a rect function having value 1 from
time 0 to 4ms and 0 from 4 to 8ms. In frequency domain Z is the convolution
output of DFT of x[n] and the rect function. 
%}
