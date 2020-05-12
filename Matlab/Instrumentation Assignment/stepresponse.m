clear
clc
%%
t = 0:0.01:20;
u = 1*double(t>=1);
s = tf('s');
w = [1 0.5 2 10 50] ;
z = [0 0.3 0.6  1 1.5 3];
figure(1)
hold()
plot(t,u,'--','Linewidth',2)
for i = 1:numel(z)
    G = (w(1)^2)/(s^2 + w(1)^2 + 2*z(i)*w(1)*s);
    y = lsim(G,u,t);
    plot(t,y,'Linewidth',2)
end

legend('Input signal','Zeta = 0','Zeta = 0.3','Zeta = 0.6','Zeta = 1','Zeta = 1.5','Zeta = 3')
title('Step response for Wn = 1')
xlabel('Time')
ylabel('Amplitude')
%%
figure(2)
hold()
plot(t,u,'--','Linewidth',2)
z1 = 0.3; 
for i = 1 : numel(w)
    G = (w(i)^2)/(s^2 + w(i)^2 + 2*z1*w(i)*s);
    y = lsim(G,u,t);
    plot(t,y,'Linewidth',2)
end
legend('Input signal','Wn = 1','Wn = 0.5','Wn = 2','Wn = 10','Wn = 50')
title('Step response for different Wn for underdamped system Zeta = 0.3')
xlabel('Time')
ylabel('Amplitude')
%%
figure(3)
hold()
plot(t,u,'--','Linewidth',2)
z1 = 1; 
for i = 1 : numel(w)
    G = (w(i)^2)/(s^2 + w(i)^2 + 2*z1*w(i)*s);
    y = lsim(G,u,t);
    plot(t,y,'Linewidth',2)
end
legend('Input signal','Wn = 1','Wn = 0.5','Wn = 2','Wn = 10','Wn = 50')
title('Step response for different Wn for critically damped system Zeta = 1')
xlabel('Time')
ylabel('Amplitude')
%%
figure(4)
hold()
plot(t,u,'--','Linewidth',2)
z1 = 4; 
for i = 1 : numel(w)
    G = (w(i)^2)/(s^2 + w(i)^2 + 2*z1*w(i)*s);
    y = lsim(G,u,t);
    plot(t,y,'Linewidth',2)
end
legend('Input signal','Wn = 1','Wn = 0.5','Wn = 2','Wn = 10','Wn = 50')
title('Step response for different Wn for overdamped system Zeta = 4')
xlabel('Time')
ylabel('Amplitude')
%%
clear
clc