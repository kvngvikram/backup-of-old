c=0.275 

M=160;% for the other case put M=240 wc=0.275*pi; 
w=hanning(M+1);%for the other case put blackman for n=0:M 
hd(n+1)=pi*sinc(wc*(n-M/2)/pi)/4; 
h(n+1)=hd(n+1)*w(n+1); end f=-pi:0.01:pi; for k=0:numel(f)-1 H(k+1)=0; for n=0:M; 
H(k+1)=H(k+1)+h(n+1).*exp(-j.*n.*f(k+1)); end end wk=-pi; for k=0:length(f)-1 wk=wk+.01; if(abs(wk)<=pi/4) Hd(k+1)=1; else Hd(k+1)=0.01; end end figure; subplot(2,1,1) 
plot(-pi:0.01:pi,20*log10(abs(Hd))); subplot(2,1,2) plot(-pi:0.01:pi,20*log10(abs(H))) 
