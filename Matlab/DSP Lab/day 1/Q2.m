x = [ 2 5 1 6 ]

% a 
a = x + 16 

% b 
b = x
for i=1:numel(x)
    if rem(i,2)==1 
        b(i)=x(i)+3;
    end
end
b

% c
c = sqrt(x)

% d 
d = x.^2

