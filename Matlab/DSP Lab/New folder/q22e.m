n=1:21;
u = [zeros(1,10) 1 zeros(1,10)];
stem(n,u);
xlabel('Time index n');
ylabel('Amplitude');
title('Unit Sample Sequence');