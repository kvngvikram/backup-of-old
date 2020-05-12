n = 0:74;
xmean = 0;
xstd = sqrt(3);
x = xstd*randn(1,length(n)) + xmean;
stem(n,x);
title('Gaussian Random Sequence');
xlabel('Time index n');
ylabel('Amplitude');