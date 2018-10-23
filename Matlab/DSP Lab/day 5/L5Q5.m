clear;clc;
%%
%{
t=-1:0.0001:0.4;
z=sin(2*pi*217*t)+sin(2*pi*200*t);
f=22100;
p=audioplayer(z,f);
%play(p);
for j=1:3
for i = 1:2
pause(0.8);
play(p);
end
pause(0.65)
end
%}
%% 
% Sample
N = [1 3 5 6 7];
T = [.5 .5 .5 .5 .5];
sf = 5000;
%N = input('Enter the numbers');
%T = input('Enter the time of pressing these numbers');
%sf = input('Enter the sample frequency')

step = 1/sf;

if numel(N)~=numel(T)
    disp("Inputs are not given correctly")
    if numel(N)>numel(T)
        T = [T step*ones(1,(numel(N)-numel(T)))];
    else
        N = [N zeros(1,(numel(T)-numel(N)))];
    end
end


for i = 1:numel(N)
    n = N(i);
    z = makeDTMFsignal(n,T(i),step);
    p=audioplayer(z,sf);
    play(p);
    pause(T(i))
end
    
    