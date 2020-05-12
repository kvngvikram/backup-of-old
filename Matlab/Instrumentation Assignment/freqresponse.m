clear 
clc 
%%
w = 0:0.01:20;
w = 1j*w;
z = [3 1.5 1 0.8 0.6 0.4 0.2]
%%
Wn = 1;
figure()
hold()
for i = 1:numel(z)
    H = (Wn^2)./(w.*w + Wn^2 + w.*2*z(i)*Wn);
    plot(real(w/1j),abs(H),'Linewidth',2)

end
xlabel('Frequency')
ylabel('Gain')
legend('Zeta = 3','Zeta = 1.5','Zeta = 1','Zeta = 0.8','Zeta = 0.6','Zeta = 0.4','Zeta = 0.2')
title('Frequency response for Wn = 1')
figure()
hold()
for i = 1:numel(z)
    H = (Wn^2)./(w.*w + Wn^2 + w.*2*z(i)*Wn);
    plot(real(w/1j),phase(H)*180/pi,'Linewidth',2)

end
xlabel('Frequency')
ylabel('Phase')
legend('Zeta = 3','Zeta = 1.5','Zeta = 1','Zeta = 0.8','Zeta = 0.6','Zeta = 0.4','Zeta = 0.2')
title('Phase response for Wn = 1')


%%
Wn = 5;
figure()
hold()
for i = 1:numel(z)
    H = (Wn^2)./(w.*w + Wn^2 + w.*2*z(i)*Wn);
    plot(real(w/1j),abs(H),'Linewidth',2)

end
xlabel('Frequency')
ylabel('Gain')
legend('Zeta = 3','Zeta = 1.5','Zeta = 1','Zeta = 0.8','Zeta = 0.6','Zeta = 0.4','Zeta = 0.2')
title('Frequency response for Wn = 5')
figure()
hold()
for i = 1:numel(z)
    H = (Wn^2)./(w.*w + Wn^2 + w.*2*z(i)*Wn);
    plot(real(w/1j),phase(H)*180/pi,'Linewidth',2)
end
xlabel('Frequency')
ylabel('Phase')
legend('Zeta = 3','Zeta = 1.5','Zeta = 1','Zeta = 0.8','Zeta = 0.6','Zeta = 0.4','Zeta = 0.2')
title('Phase response for Wn = 5')
%%
Wn = 10;
figure()
hold()
for i = 1:numel(z)
    H = (Wn^2)./(w.*w + Wn^2 + w.*2*z(i)*Wn);
    plot(real(w/1j),abs(H),'Linewidth',2)

end
xlabel('Frequency')
ylabel('Gain')
legend('Zeta = 3','Zeta = 1.5','Zeta = 1','Zeta = 0.8','Zeta = 0.6','Zeta = 0.4','Zeta = 0.2')
title('Frequency response for Wn = 10')
figure()
hold()
for i = 1:numel(z)
    H = (Wn^2)./(w.*w + Wn^2 + w.*2*z(i)*Wn);
    plot(real(w/1j),phase(H)*180/pi,'Linewidth',2)

end
xlabel('Frequency')
ylabel('Phase')
legend('Zeta = 3','Zeta = 1.5','Zeta = 1','Zeta = 0.8','Zeta = 0.6','Zeta = 0.4','Zeta = 0.2')
title('Phase response for Wn = 10')
%%
clear
clc

