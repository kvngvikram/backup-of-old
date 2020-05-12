A=[2 4 1 ; 6 7 2 ; 3 5 9 ]

%a
x1 = A(1,:) % assigning first row to x1

%b 
y = A(2:3,:)% assigning last two rows to y

%c
c = sum(A,1)% sum of columns of A

%d
d = sum(A,2)

%e
%standard error = standard deviation / sqrt(n)
for i=1:3 % for different columns
    se(i) = std(A(:,i))/sqrt(3);
end
se
