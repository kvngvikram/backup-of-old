r=0.8;
n=0:20;
y=r.^n.*exp(j*pi.*n/3);
plot(n,angle(y))
xlabel('n');
ylabel('Angle of y');