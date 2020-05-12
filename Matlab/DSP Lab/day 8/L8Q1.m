%% 
clear;clc;
%% Defining the parameters
wpass = 0.25*pi;
wstop = 0.3*pi;
passbandgain = 1;
stopbandgain = 0;
passbanddelta = 0.01;
stopbanddelta = 0.01;
M = 300; 
circshiftvalue = 0;
%% Frequency sampelling

w = -pi+2*pi/(M+1):2*pi/(M+1):pi;

x1 = wpass;
x2 = wstop;
y1 = passbandgain;
y2 = stopbandgain;
slope = abs((y1-y2)/(x1-x2));
H = zeros(1,numel(w));
for i = 1:numel(w)
    if abs(w(i)) < wpass
        H(i) = passbandgain*exp(-1j*w(i)*M/2);
    elseif (w(i) > wpass) & (w(i) < wstop) 
        H(i) = y1 - slope*(w(i)-x1);
    elseif (w(i)<-wpass) & (w(i)>-wstop)
        H(i) = y1 - slope*(-x1-w(i));
    end
end

figure()
stem(w,abs(H))
title('frequency sampled H')
xlabel('---> w')
ylabel('---> Amplitude')

h = ifft(fftshift(H));
n = 0 : numel(h)-1;


%% Circ shifting obtained h[n]
h = circshift(h,circshiftvalue);
figure()
stem(n,real(h))
title('h[n] ')
xlabel('---> n')
ylabel('---> amplitude')

%% Finding DTFT of obtained h[n]
W = -pi:0.001:pi; 
F = zeros(1,numel(W));
for i = 1:numel(W)
    for j = 1:numel(n)
        F(i) = F(i) + h(j)*exp(-1i*W(i)*n(j));
    end
end

w = -pi : 0.001:pi; 
H = zeros(1,numel(w));
for i = 1:numel(w)
    if abs(w(i)) < wpass
        H(i) = passbandgain*exp(-1j*w(i)*M/2);
    elseif (w(i) > wpass) & (w(i) < wstop) 
        H(i) = y1 - slope*(w(i)-x1);
    elseif (w(i)<-wpass) & (w(i)>-wstop)
        H(i) = y1 - slope*(-x1-w(i));
    end
end



figure()
subplot(2,2,1)
plot(W,abs(F),'linewidth',2)
xlabel('---> w')
ylabel('---> |H(w)|')
title('Obtained Frequency response')
subplot(2,2,2)
plot(W,unwrap(angle(F)))
xlabel('---> w')
ylabel('---> <H(w)')
title('Obtained phase response')
subplot(2,2,3) 
plot(w,abs(H),'linewidth',2)
xlabel('---> w')
ylabel('---> |H(w)|')
title('Required Frequency response')
subplot(2,2,4)
plot(w,unwrap(angle(H)))
title('Required phase response')
xlabel('---> w')
ylabel('---> <H(w)')
