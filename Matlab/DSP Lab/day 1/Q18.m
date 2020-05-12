%random number between -2 to 2
ans = 4*rand(1,100)-2;
stem(ans)
title('Random Sequence');
xlabel('Time index n');
ylabel('Amplitude');