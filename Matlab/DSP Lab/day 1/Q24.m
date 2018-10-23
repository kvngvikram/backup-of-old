r=0.8;
n=0:20;
y=r.^n.*exp(j*pi.*n/3);
plot(n,abs(y))
title('Magnitude')
xlabel('n');
ylabel('Magnitude of y');
figure()
plot(n,angle(y))
title('Phase')
xlabel('n')
ylabel('Angle of y')