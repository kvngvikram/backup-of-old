clear
clc
%%
z = 0:0.01:1-0.01;
mp = exp(-z.*pi./((1-z.^2).^0.5));
plot(z,mp*100,'r','Linewidth',2)
title('Variation of % overshoot with Zeta')
xlabel('Zeta')
ylabel('%')
%title()
%%
clear
clc