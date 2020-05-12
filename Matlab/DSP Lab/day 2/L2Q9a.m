% a)
clear;

t = 2;  % time 
sf = 22100; %sample frequency 
f = 500; % frequency
n=0:t/sf:t;
x=sin(2*pi*f*n);   % defining the signal
p=audioplayer(x,sf); % making a audioplayer object with signal and samplerate
play(p); % playing the audio
