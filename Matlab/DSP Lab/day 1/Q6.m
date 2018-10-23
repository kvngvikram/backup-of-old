% time 
t = [1790:2000];

% population
p = 197273000./(1+exp(-0.0313.*(t-1913.25)));

% plotting
plot(t,p)
title('population vs time')
xlabel('time in years')
ylabel('population of USA')
hold
 
p2020 = 197273000/(1+exp(-0.0313*(2020-1913.25)))