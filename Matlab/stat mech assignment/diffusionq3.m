clear;clc;
%%
N = input('enter the number of step') ; %number of steps 
W = input('enter the number of walkers') ; %number of walkers 

p1 = 0.25;
p2 = 0.5; 
p3 = 0.75; 

x = zeros(1,W); 
y = zeros(1,W);
r = zeros(1,W);
u = zeros(1,W);
l = zeros(1,W);
d = zeros(1,W);

meanx = zeros(1,N);
meany = zeros(1,N);
varx = zeros(1,N); 
vary = zeros(1,N);

b = zeros(2*N+1,2*N+1); 
b(N+1,N+1) = W ; 

figure()
surf([-N:N],[-N:N],b)
hold()

for n = 1:N
    for w = 1:W
        a = myrand(p1,p2,p3); 
        if a == 0
            r(w) = r(w) + 1;
        elseif a == 1 
            u(w) = u(w) + 1;  
        elseif a == 2 
            l(w) = l(w) + 1; 
        else 
            d(w) = d(w) + 1; 
        end
    end
    
    x = r - l ; 
    y = u - d ;
    
    meanx(n) = sum(r)/W;
    meany(n) = sum(u)/W;
    
    
    varx(n)=0;
    for w=1:W
        varx(n)=varx(n)+ (r(w)-mean(n))^2;
    end
    varx(n) = varx(n)/W; %Varaince

    vary(n)=0;
    for w=1:W
        vary(n)=vary(n)+ (u(w)-mean(n))^2;
    end
    vary(n) = vary(n)/W; %Varaince
    %{
    clf()
    scatter(x,y)
    axis([-N N -N N])
    pause(0.1)
    %}
    for i = 1:2*N+1
        for j = 1:2*N+1
            b(i,j) = 0; 
            for w = 1:W
                if x(w) == i-N-1 & y(w) == j-N-1
                    b(i,j) = b(i,j) + 1 ; 
                end           
            end
        end
    end
    
    clf()
    surf([-N:N],[-N:N],b)
    %bar3(b)
    s.edgecolour = 'none'; 
    pause(0.5)
end

figure()
subplot(2,2,1)
plot(meanx)
title('mean along x')
subplot(2,2,3)
plot(meany)
title('mean along y')
subplot(2,2,2)
plot(varx.^0.5)
title('varience along x')
subplot(2,2,4)
plot(vary.^0.5)
title('varience along y')