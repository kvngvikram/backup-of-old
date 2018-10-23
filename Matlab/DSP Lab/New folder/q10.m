x = [1 4 8]
y = [2 1 5]
A = [3 1 6 ; 5 2 7]
w  = x + y %works
 e =  x + A % matrix dimension not matching
  r  = x' + y % matrix dimension not matching
  t  = A - [x' y'] % matrix dimension not matching
y  =  [x ; y'] % matrix dimension not matching
 u  = [x ; y] % works
 o = A - 3 % works
 
 
  