x = 1:10
y = [3 1 5 6 8 2 9 4 7 0]
q = (x > 3) & (x < 8) % true when greater than 3 and less than 8
w = x(x > 5) % vector part of x when x greater than 5
e = y(x <= 4)% vector part of y when x less than or equal to 4
r = x( (x < 2) | (x >= 8) ) % vector part of x when x greater than or equal to 8 or less than 2
t = y( (x < 2) | (x >= 8) ) % vector part of y when x greater than or equal to 8 or less than 2
u = x(y < 0) % empty matrix
