omega=-pi:0.01:pi;
M=100; %Length of window=M+1
w=bartlett(M+1);% window name change name here for obtaining different window
W=0;
for n=0:M
W=W+ w(n+1)*exp(-j.*omega*n);
end;
subplot(2,1,1);
plot(omega,20*log10(abs(W)));
xlabel('Frequency,w');
ylabel('Magnitude,dB');
title('Magnitude Response');
subplot(2,1,2);
plot(omega,unwrap(angle(W)));
xlabel('Frequency,w');
ylabel('Angle,rad');
title('Phase Response');
%%
M=input('Enter the value of M ');
f=-pi:0.01:pi;
wc=pi/4;
w=bartlett(M+1); %window function for other windows change the name
H=0;
for n=0:M
hd(n+1)=sinc(wc*(n-M/2))/4;
h(n+1)=w(n+1)*hd(n+1);
end
for k=0:numel(f)-1
H(k+1)=0;
for n=0:M;
H(k+1)=H(k+1)+h(n+1).*exp(-1j.*n.*f(k+1));
end
end
figure
subplot(2,1,1)
plot(f,20*log10(abs(H)));
subplot(2,1,2)
plot(f,angle(H))