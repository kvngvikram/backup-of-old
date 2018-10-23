% c

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


% the peaks will be the overtones of two frequencies
% peaks can be identified only if freq difference is less 
% frequency of peaks = f1~f2

disp('Hello!')

