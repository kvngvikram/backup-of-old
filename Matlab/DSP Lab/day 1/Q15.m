x = [ 1 2 3 ; 4 5 6 ; 7 8 9 ]
y = [ 9 8 7 ; 6 5 4 ; 3 2 1 ]

%a y=rem(x,2)vs.y=logical(rem(x,2)) 
yrem=rem(x,2)
ylogical=logical(rem(x,2))

%b y=~rem(x,2)vs.y=~logical(rem(x,2))
nyrem=~rem(x,2)
nylogical=~logical(rem(x,2))
