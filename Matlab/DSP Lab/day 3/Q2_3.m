% This code is for both questions 2 and 3

clear
clc

% n and h can be any arbitary signal
% n can start and end at any point in Real line
% Corresponding value of h is given
% Here the signal for problem 2 is used
n = -10:10;
h = n.*double(n>=0 & n<=10);
%h = sin(n); % Just an other arbitary h
%
% User defined Inputs
dbscale = 10 ;  % will be True if 1
ActualFreqScale = -10 ;  % will be True if -1
SampleFreq = 10;

% Just plotting
stem(n,h)
title('Impulse response')
xlabel('n')
ylabel('Amplitude')


%Making variable names smaller
AF = ActualFreqScale;
DB = dbscale;

%Range of Discreet frequencies for which Transform is calculated
w = -10:0.01:10;
 
% Defining Transform variable F with same number of elements as w
F = w*0;

% First for loop to calculate F at each w
for i = 1:numel(w)
    % Second for loop to calculate summation of h[n]*exp(-iwn) at different
    % n
    for j = 1:numel(n)
        F(i) = F(i) + h(j)*exp(-1i*w(i)*n(j));
    end
end

% depending on the user input scale if frequency is changed
if AF == -1
    w = w*SampleFreq;
end

% Amplitude and Phase of Transform are plotted accordingly depending on the
% user input of scale

figure()
subplot(2,1,1)
if DB == 1 
    plot(w,20*log(abs(F)))
    title('Absolute Value of Transform')
    ylabel('Log scale')
else 
    plot(w,abs(F))
    title('Absolute Value of Transform')
    ylabel('Amplitude')
end

if AF == -1
    xlabel('Actual Frequency in Hz')
else
    xlabel('Discrete Frequency')
end

subplot(2,1,2)
plot(w,(angle(F)*180/pi))
title('Phase of Transform')
ylabel('Phase in degrees')
if AF == -1
    xlabel('Actual Frequency in Hz')
else
    xlabel('Discrete Frequency')
end