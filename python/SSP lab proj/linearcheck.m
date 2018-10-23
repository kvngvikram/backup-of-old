distance = 10;
g = 1000;

lamda = [400:700];
position = distance*tan(asin(g*0.000001*lamda));

plot(lamda,position)

