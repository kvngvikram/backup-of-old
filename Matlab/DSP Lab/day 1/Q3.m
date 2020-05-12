% defining row arrays x, y 
x = [3 2 6 8]
y = [4 1 3 5]

% taking transpose
x = x.';
y = y.';

% saving x and y to recover them after manipulation 
x1 = x ; 
y1 = y ; 

% a
y = y + x 

y = y1;
x = x1;

% b 
x = x.^y

y = y1;
x = x1;

% c 
y = y./x

y = y1;
x = x1;

% d 
z = x.*y

% e 
w = sum(z)

% f 
%dot product of x and y subracted with w
x'*y - w 

