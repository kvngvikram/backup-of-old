% w[n] is a rectangular window of length M + 1 

M1 = 10; 
M2 = 50; 
M3 = 100; 
df = 0.001; 
%%
f = 0 : df : 2*pi ;

n1 = 0:M1;
w1 = 1+n1*0; 
n2 = 0:M2;
w2 = 1+n2*0; 
n3 = 0:M3;
w3 = 1+n3*0; 
%%
W1 = zeros(1,numel(f));
for i = 1:numel(f)
    for j = 1:numel(n1)
        W1(i) = W1(i) + w1(j)*exp(-1j*f(i)*n1(j));
    end 
end

W2 = zeros(1,numel(f));
for i = 1:numel(f)
    for j = 1:numel(n2)
        W2(i) = W2(i) + w2(j)*exp(-1j*f(i)*n2(j));
    end 
end
W3 = zeros(1,numel(f));
for i = 1:numel(f)
    for j = 1:numel(n3)
        W3(i) = W3(i) + w3(j)*exp(-1j*f(i)*n3(j));
    end 
end
%%
figure()
title('DTFT of w[n]')
subplot(2,1,1)
hold()
title('Normalised Amplitudes in log scale of different window functions')
plot(f,20*log10(abs(W1)/abs(W1(1))),'b','LineWidth',2)
plot(f,20*log10(abs(W2)/abs(W2(1))),'r','LineWidth',2)
plot(f,20*log10(abs(W3)/abs(W3(1))),'g','LineWidth',2)
legend('M = 10','M = 50','M = 100')
xlabel('--> Frequency in radiens')
ylabel('--> 20log|W|') 

subplot(2,1,2)
hold()
title('Phase plot')
plot(f,unwrap(angle(W1)*180/pi),'b','LineWidth',2)
plot(f,unwrap(angle(W2)*180/pi),'r','LineWidth',2)
plot(f,unwrap(angle(W3)*180/pi),'g','LineWidth',2)
legend('M = 10','M = 50','M = 100')
xlabel('--> Frequency in radiens')
ylabel('--> Phase angle in degrees')

%%
SampleFrequency = 8 ; % kHz
CutoffFrequency = 1 ; % kHz

%%
sf = SampleFrequency; 
cf = CutoffFrequency; 

w_c = pi*cf/sf; 

H = 1*double(f<w_c | f>(2*pi - w_c));  

h1 = zeros(1,numel(n1));
for i = 1:numel(n1)
    for j = 1:numel(f)
        h1(i) = h1(i) + H(j)*exp(1j*f(j)*n1(i))*df/(2*pi); 
    end
end

h2 = zeros(1,numel(n2));
for i = 1:numel(n2)
    for j = 1:numel(f)
        h2(i) = h2(i) + H(j)*exp(1j*f(j)*n2(i))*df/(2*pi); 
    end
end

h3 = zeros(1,numel(n3));
for i = 1:numel(n3)
    for j = 1:numel(f)
        h3(i) = h3(i) + H(j)*exp(1j*f(j)*n3(i))*df/(2*pi); 
    end
end


%%
figure()
subplot(3,1,1)
stem(n1,real(h1))
title('IDTFT of h[n] with M = 10')
xlabel('--> n')
ylabel('--> Amplitude')
subplot(3,1,2)
stem(n2,real(h2))
title('IDTFT of h[n] with M = 50')
xlabel('--> n')
ylabel('--> Amplitude')
subplot(3,1,3)
stem(n3,real(h3))
title('IDTFT of h[n] with M = 100')
xlabel('--> n')
ylabel('--> Amplitude')

%%
H1 = zeros(1,numel(f));
for i = 1:numel(f)
    for j = 1:numel(n1)
        H1(i) = H1(i) + h1(j)*exp(-1j*f(i)*n1(j));
    end 
end 

H2 = zeros(1,numel(f));
for i = 1:numel(f)
    for j = 1:numel(n2)
        H2(i) = H2(i) + h2(j)*exp(-1j*f(i)*n2(j));
    end 
end

H3 = zeros(1,numel(f));
for i = 1:numel(f)
    for j = 1:numel(n3)
        H3(i) = H3(i) + h3(j)*exp(-1j*f(i)*n3(j));
    end 
end

%%
figure()
subplot(2,1,1)
hold()
title('Normalised Amplitudes in log scale for different h[n]')
plot(f,20*log10(abs(H1)/abs(H1(1))),'b','LineWidth',2)
plot(f,20*log10(abs(H2)/abs(H2(1))),'r','LineWidth',2)
plot(f,20*log10(abs(H3)/abs(H3(1))),'g','LineWidth',2)
xlabel('--> Frequency in radians')
ylabel('--> 20log|H|')
legend('M = 10','M = 50','M = 100')

subplot(2,1,2)
hold()
title('Phase for different h[n]')
plot(f,unwrap(angle(H1)*180/pi),'b','LineWidth',2)
plot(f,unwrap(angle(H2)*180/pi),'r','LineWidth',2)
plot(f,unwrap(angle(H3)*180/pi),'g','LineWidth',2)
xlabel('--> Frequency in radians')
ylabel('--> phase in degrees')
legend('M = 10','M = 50','M = 100')