n = 0:74;
mean = 0;
std = sqrt(3);
x = std*randn(1,length(n)) + mean;
stem(n,x);
title('Gaussian Random Sequence');
xlabel('Time index n');
ylabel('Amplitude');