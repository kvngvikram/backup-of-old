function partialFractionExpander(zer, mzeros, poles, mpoles)
zer=[1 2];
mzeros=[1 1];
poles=[3];
mpoles=[4];
syms z H N D
K=zeros(length(mpoles),max(mpoles));
for i=1:length(poles)
for j=1:mpoles(i)
%Computing residue
N=1*(z-zer).^mzeros;
D=(z-poles).^mpoles;
H=prod(N)/prod(D);
d=diff(H*(z-poles(i))^mpoles(i),j-1);
a=subs(d, z, poles(i));

K(i,j)=1/factorial(mpoles(i)-j)*a;
end;
end;
syms z X
Y=0;
for i=1:length(mpoles)
for j=1:mpoles(i)
Y=Y+K(i,j)/(z-poles(i))^j;
end;
end;
Y
end