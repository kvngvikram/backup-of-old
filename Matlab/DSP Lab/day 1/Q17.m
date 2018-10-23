sum = 0;
count = 0;
while sum < 20
  count = count + 1;
  x = rand;
  sum = sum + x;
end

disp(['To add more than 20 it number of random numbers taken is ',int2str(count)])

count = 0;
x=rand;
while x < 0.8 || x > 0.85
  count = count + 1;
  x = rand;
end
disp(['Number of iterations to get random number between 0.8 and 0.85 is ',int2str(count)])

count = 0;
mean =0;
while abs(mean - 0.5) > 0.01
  count = count + 1;
  x = rand;
  mean = ((count-1)*mean + rand(1,1))/count;
end
disp(['Number of iterations for mean to be within 0.01 of 0.5 is ',int2str(count)])