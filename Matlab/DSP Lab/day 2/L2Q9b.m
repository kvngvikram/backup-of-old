
% b)
clear;

t=0:0.001:30;                   
y=chirp(t,40,10,400,'logarithmic'); 
% 40 is initial frequency  
% 10 is the frequency steps in which frequency will be increased
% 400 is maximum frequency 
% 'logerithmic' is a parameter for particular kind of chirp
sf=1000;
p=audioplayer(y,sf);
play(p);
disp('Please be patient')