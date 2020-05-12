% d is linear and not time invarient
clear;
n=-20:20;           

%Defining x1 and x2
x1 = 1*double(n>=0 & n<=10);
x2 = 1*double(n>0 & n<=10);


%Checking linearity and time invarience

x=x1+x2;
xt = circshift(x,4); % 4 is arbitary number to check time invarience


% output functions
y  = x ;
yt = xt;
y1 = x1;
y2 = x2;
n = 2*n;

subplot(1,3,1);
stem(n,y1+y2);
xlabel('Index,n');
ylabel('y1+y2');
title('y(x1)+y(x2) v/s n');
 
subplot(1,3,2); 
stem(n,y);
xlabel('Index,n');
ylabel('y');
title('y = y(x1+x2) v/s n');   


subplot(1,3,3); 
stem(n,yt);
xlabel('Index,n');
ylabel('y');
title('y(n-4) v/s n'); 