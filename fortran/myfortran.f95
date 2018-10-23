program myprogram


implicit  none

integer :: myn 
complex :: cc
real :: a, b , c
integer :: m
logical :: myflag 
real :: r, nr(10) 
real, parameter :: g = 9.81 
logical :: anotherflag 
integer :: myarray(10) , newarray(10)
integer :: i,k 

myarray= (/ 1,2,3,4,5,6,7,8,9,0 /)
print*, myarray

do i=3,13
print*, i
newarray(i) = i 
end do  

nr = 1 
print*, nr 
print*, (nr>0)

do i= 1,10,2 
print*, i
end do 

i = 0 

do while (i<10)
i = i + 1 
print*, i
end do 



print*, '\t',i,'\n'
print*, newarray 


myflag = .true. 
print*, 'my flag is',myflag 

anotherflag = .not.myflag 
print*, 'another flag is',anotherflag 

a = 23
b = 3
c = a*b+45
print*, 'hello',c

m = c 
print*, 'new integer',m 

cc = 4 
print*, 'complex ? ',cc,'huh ? '


myn = 45 
print*, 'myn is ',myn

end program myprogram
