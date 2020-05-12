% circular convolution

x1 = [4 2 6 3 8 1]
x2 = [3 8 6 9 6 7]

% checking if length of arrays are equal
% if not then zeros are padded at the end
if numel(x1) == numel(x2)
    disp('array length matching..')
else
    disp('error !! array legths not equal')
    if numel(x1)>numel(x2)
        disp('padding zeros on the right of X2')
        x2 = padarray(x2,[0 (numel(x1)-numel(x2))],0,'post')
    else
        disp('padding zeros on the right of X1')
        x1 = padarray(x1,[0 (numel(x2)-numel(x1))],0,'post')
    end    
end

c = zeros(size(x1));
x1 = flip(x1)';
x2=x2';
for i = 1 : numel(x1)
    c(i) = sum(x2.*circshift(x1,i));
end
disp('Final array after circular convolution is ')
c

