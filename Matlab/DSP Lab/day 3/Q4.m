function y= discreteTimeConvolve(x,h) 
    x = [x zeros(1,numel(h)-1)];
    h = [h zeros(1,numel(x)-1)];
    x = [zeros(1,numel(x) x];
    h = [zeros(1,numel(h) h];
        
    y = 0*x;
    
    for i = 1 : numel(y)
        y(i) = 