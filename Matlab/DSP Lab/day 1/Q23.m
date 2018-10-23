%a
resolution = 0.01;
n = -10:resolution:10;
a = 3*sin(2*pi*n + pi/3);
figure()
hold()
plot(n,a,'b')
xlabel('n')
ylabel('Amplitude')

%b 
b = 5*cos(2*pi*n/3 + pi/4) + 2.5*sin(pi*n/3 + pi/4);
plot(n,b,'r')
legend('first','second')