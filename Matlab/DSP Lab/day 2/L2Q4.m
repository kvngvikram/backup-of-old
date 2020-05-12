clc
clear

%a 
x1 = [0 4 3 5 6 7 2];
n1 = -(numel(x1)-1)/2 : (numel(x1)-1)/2

figure()
hold()
title('first part')
even1 = (x1 + flip(x1))/2;
odd1  = (x1 - flip(x1))/2;

stem(n1,even1,'b')
stem(n1,odd1,'r')
legend('even','odd')
xlabel('index')
ylabel('amplitude')


%b
n2 = -0.01:0.0005:0.01;
x2 = sin(2*pi*100*n2)+cos(pi*100*n2);

figure()
hold()
title('second part')
even = (x2 + flip(x2))/2;
odd  = (x2 - flip(x2))/2;
stem(n2,even,'b')
stem(n2,odd,'r')
legend('even','odd')
xlabel('index')
ylabel('amplitude')