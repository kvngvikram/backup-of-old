% X is the DFT
function X = mydft1(x)
    N = numel(x);

    for k = 1:N   % number of elements in x and X are equal
        X(k) = 0; % for each element of X
        for n = 1:N  % summation for all elements in x
            % k and n should be calculated from 0 but index starts from 1
            X(k)=X(k)+x(n)*exp(-1i*2*pi*(k-1)*(n-1)/N);
        end
    end

end