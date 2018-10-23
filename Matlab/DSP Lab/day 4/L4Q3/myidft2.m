function x = myidft2(X)
x = X*inv(dftmtx(numel(X)));
end