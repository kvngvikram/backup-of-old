n=-10:10;
u = [zeros(1,10) ones(1,11)];
stem(n,u)
xlabel('Time index n');
ylabel('Amplitude');
title('Unit Impulse Signal');