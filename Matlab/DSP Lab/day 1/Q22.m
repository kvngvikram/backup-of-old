n = -10:10;

%a) Impulse signal
figure()
delta = [zeros(1,10) 1 zeros(1,10)];
stem(n,delta);
xlabel('Time index n');
ylabel('Amplitude');
title('Unit Impulse Signal');


%b) Step signal
figure()
delta = [zeros(1,10) ones(1,11)];
stem(n,delta);
xlabel('Time index n');
ylabel('Amplitude');
title('Unit Step Signal');

%c) Ramp signal
n=0:10;
ramp=n;
figure()
stem(n,ramp)
xlabel('Time index n');
ylabel('Amplitude');
title('Ramp Signal');

%d) Real exponential signal
a=0.9;
e=exp(-a.*n);
figure()
stem(n,e)
xlabel('Time index n');
ylabel('Amplitude');
title('Real Exponential Signal');

%e) Shifted impulse
n=-10:10;
n1 = (n(1)+11):(n(numel(n))+11)
u = [zeros(1,10) 1 zeros(1,10)];
figure()
stem(n1,u);
xlabel('Time index n');
ylabel('Amplitude');
title('Shifted impulse');

%f) Advanced impulse
n2 = (n(1)-7):(n(numel(n))-7)
u = [zeros(1,10) ones(1,11)];
figure()
stem(n2,u)
xlabel('Time index n');
ylabel('Amplitude');
title('Advanced step signal');