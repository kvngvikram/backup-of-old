n=0:10;
a=0.9;
u=exp(-a.*n);
stem(n,u)
xlabel('Time index n');
ylabel('Amplitude');
title('Real Exponential Signal');