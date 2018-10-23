function z=makeDTMFsignal(n,T,step)
    if n==1 
        F1 = 1209;
        F2 = 697; 
    elseif n==2 
        F1 = 1336;
        F2 = 697;
    elseif n == 3 
        F1 = 1477; 
        F2 = 697;
    elseif n == 4 
        F1 = 1209; 
        F2 = 770;
    elseif n == 5 
        F1 = 1336; 
        F2 = 770;
    elseif n == 6 
        F1 = 1477; 
        F2 = 770;
    elseif n == 7 
        F1 = 1209; 
        F2 = 852;
    elseif n == 8 
        F1 = 1336; 
        F2 = 852;
    elseif n == 9 
        F1 = 1477; 
        F2 = 852;
    elseif n == 10
        F1 = 1336; 
        F2 = 941;
    elseif n == 11 % *
        F1 = 1209; 
        F2 = 941;
    elseif n == 12 % #
        F1 = 1477; 
        F2 = 941;
    elseif n == 13 % A
        F1 = 1633; 
        F2 = 697;
    elseif n == 14 % B
        F1 = 1633; 
        F2 = 770;
    elseif n == 15 % C 
        F1 = 1633; 
        F2 = 852;
    elseif n == 16 % D 
        F1 = 1633; 
        F2 = 941;
    end
    
    t = 0:step:T-step; 
    z=sin(2*pi*F1*t)+sin(2*pi*F2*t);

end