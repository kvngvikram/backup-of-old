% x is the IDFT of X
function x = myidft1(X)
    K = numel(X);

    for n = 1:K   % number of elements in x and X are equal
        x(n) = 0;
        for k = 1:K
            x(n)=x(n)+X(k)*exp(1i*2*pi*(n-1)*(k-1)/K);
        end
        x(n) = x(n)/K;
    end

end