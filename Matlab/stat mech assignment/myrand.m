function number = myrand(p1,p2,p3)
r = rand(); 

if r<p1
    number = 1; 
elseif r>p1 & r<p2
    number = 2; 
elseif r>p2 & r<p3 
    number = 3; 
else 
    number = 4; 
end
