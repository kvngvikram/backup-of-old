
clc;
clear;
% the two signals are h and g
g=[0 1 2 3 4];
h=[0 0 0 1 1 1 1];

%a
%{
Manually caluclated circular convolution of two signals is y = [1 1 1 1 1]
for n = [0 1 2 3 4 ] 
%}

N1=length(g);
N2=length(h);
N=max(N1,N2);

N3=N1-N2;
% padding zeros to make both the signals of same length
if(N3>0)
    h=[h,zeros(1,N3)];
else
    g=[g,zeros(1,-N3)];
end

%b
% y is the caluclated circular convolution
for n=1:N;
    y(n)=0; % initially assigning zero
    for i=1:N;
        j=n-i+1; % index shifting
        if(j<=0)
            j=N+j; % taking the recoil part for j<0
        end
        y(n)=[y(n)+(g(i)*h(j))]; % summing 
    end
end

%c
c = zeros(size(g));
x1 = flip(g)';
x2=h';
for i = 1 : numel(x1)
    c(i) = sum(x2.*circshift(x1,i));
end
% c is the circular convolution by circshift() function which circularly
% shifts the array by given number of times in aurgument

%d 
d = cconv(h,g,N);
% cconv(h,g,N) calculated circular convolution of g,h if N i.e. number of elements is given  

%e
e = ifft(fft(g).*fft(h));


subplot(2,2,1);
stem(y);
title('Caluculate circular convolution')
xlabel('---> n');
ylabel('---> Amplititude');
subplot(2,2,2);
stem(c);
title('Circular convolution using circshift()')
xlabel('---> n');
ylabel('---> Amplititude');
subplot(2,2,3);
stem(y);
title('Circular convolution using cconv()')
xlabel('---> n');
ylabel('---> Amplititude');
subplot(2,2,4);
stem(y);
title('Circular convolution from ifft() and fft()')
xlabel('---> n');
ylabel('---> Amplititude');