length=0;
n=input('enter: ');
while n>1
if rem(n,2)==0
n=n/2;
length=length+1;
else
n=3*n+1;
length=length+1;
end
end;
length