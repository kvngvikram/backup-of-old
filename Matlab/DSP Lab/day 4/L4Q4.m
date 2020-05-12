clc
clear
% n values on x axis
n = 0 : 15;


% given signal
y = cos(2*pi*0.25*n);


sf = 1;   % sample frequency
ws = 0:sf/numel(n):sf-sf/numel(n); % w axis for fft() from 0 to sf
w = ws*2*pi/sf; % w axis for fft() from 0 to 2pi

shiftws = -sf/2+sf/numel(n):sf/numel(n):sf/2; % w axis for fftshift() from -sf/2 to sf/2
shiftw = shiftws*2*pi/sf; % w axis for fftshift() from -pi to pi

% plotting the signal
figure(1)
subplot(3,1,1)
stem(n,y)
title('Plotting the original signal')
ylabel('actual amplitude')
xlabel('---> n ')

figure(2)
subplot(2,2,1)
stem(w,abs(fft(y)))
title('Magnitude of fft() of the signal')
ylabel('---> |fft(y[n])|')
xlabel('---> w rad/sed')

subplot(2,2,2)
stem(w,angle(fft(y))*180/pi)
title('Angle of FFT of the signal')
ylabel('---> < fft(y[n])')
xlabel('---> w rad/sed')

subplot(2,2,3)
stem(shiftw,abs(fftshift(y)))
title('Magnitude of fftshift() of the signal')
ylabel('---> |fftshift(y[n])|')
xlabel('---> w rad/sed')


subplot(2,2,4)
stem(shiftw,angle(fftshift(y))*180/pi)
title('Angle of fftshift() of the signal')
ylabel('---> < fftshift(y[n])')
xlabel('---> w rad/sed')

figure(1)
subplot(3,1,2)
stem(n,real(ifft(fft(y))))
title('ifft(fft()) of signal')
ylabel('Amplitude')
xlabel('---> n ')

subplot(3,1,3)
stem(n,real(ifftshift(fftshift(y))))
title('ifftshift(fftshift()) of signal')
ylabel('Amplitude')
xlabel('---> n ')