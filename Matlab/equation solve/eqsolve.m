syms y1 y2 y3 ;
vars = [ y1 y2 y3 ] ;

k = 0.103; 
p = 3.4;
r = 32.2; 

eqns = [2*y1 + y1*y3 - k*y1*y3 - 2*k*y1*y3^2 - y1*y2 - y1*y2*y3 + k*y1*y2*y3 + k*y1*y2*y3^2 - k*y3 + 1 == 0 , y1*y2 + y1*y2*y3 + y1*y2*r - y1 - 2*y1*y3 - 1 == 0 , y1*y2 + y1*y2*y3 + p*y1*y2*y3 - 2*y1 - y1*y3 - 1 == 0]; 

[ solvy1 , solvy2 , solvy3] = solve( eqns , vars )