function ztransform(x,z0)
sum=0
syms z
N=length(x)
for i=1:N
sum=sum+x(i)*z^(-(i-1))
end
ztransf=subs(sum,z,z0)
modifiedz=simplify(sum)
[N,D] = numden(modifiedz)
Zx=roots(sym2poly(N))
Px=roots(sym2poly(D))
Z=unique(Zx)
Px=unique(Px)
mZ = zeros(1,numel(Zx));
mP=zeros(1,numel(Px))
for k = 1:N
mZ(k) = sum(Zx==Z(k));
end
for k = 1:N
mP(k) = sum(Px==P(k));
end
end
function ztransform2(x, r, k)
%DFT of x[n]r^-n
y=[]
for i=1:length(x)
y(n)=x(n).*r^(-n+1)
z=fft(y)
end
end