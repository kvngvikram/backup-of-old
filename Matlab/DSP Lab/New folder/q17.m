sum = 0;
count = 0;
while sum < 20
count = count + 1;
x = rand;
sum = sum + x;
end
disp(['It took ',int2str(count),' numbers to add upto greater than or equal to 20.'])

count = 0;
x=rand;
while x < 0.8 || x > 0.85
count = count + 1;
x = rand;
end
disp(['It took ',int2str(count),' numbers before a number came between 0.8 and 0.85.'])

count = 0;
mean =0;
while abs(mean - 0.5) > 0.01
count = count + 1;
x = rand;
mean = ((count-1)*mean + rand(1,1))/count;
end
disp(['It took ',int2str(count),' numbers for mean to be within 0.01 of 0.5.'])
