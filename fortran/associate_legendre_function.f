program alf

    implicit none 


    integer :: l=3,m=1,i
    real :: x = 0.34
    real :: fact_value_here,dfact,fact
    real             :: bla = 16

    real(kind=16)                       :: Plm , Pmm , Pmmp1 , Pm_lm1 , Pm_lm2
    

    Pmm = (-1)**m * dfact(2*m-1) * (1 - x**2)**(real(m)/2)
    Pmmp1 = x*(2*m + 1)*Pmm

    print*, 'Pmm is ',Pmm
    print*, 'Pmmp1 is ',Pmmp1

    Pm_lm2 = Pmm 
    Pm_lm1 = Pmmp1
    do i=m+2,l
        print*, 'i value is ' ,i
        Plm = ( x*(2*i-1)*Pm_lm1 - (i+m-1)*Pm_lm2 )/(i-m)
        Pm_lm2 = Pm_lm1
        Pm_lm1 = Plm 
    enddo
    print*, 'Plm is ',Plm


    
    x = l

    print*, 'dfact is',dfact(7)
    print*, 'sqrt is ',sqrt(bla)
    print*, 'sin is', sin(real(90))
    print*, 'fact valule is ',fact(4)
    print*, 'xvalue is ',x
    
    fact_value_here = fact(3)
    print*, 'fact_value_here is ',fact_value_here


endprogram alf 


function dfact(n) result(dfact_value)
    implicit none
    real :: dfact_value
    integer :: n,i
    dfact_value = n
    do i=2,n,2
        dfact_value = dfact_value*(n-i) 
    enddo
end function dfact 

function fact(n) result(fact_value)
    implicit none
    real :: fact_value
    integer :: i,n
    fact_value = n
    do i=1,n-1
        fact_value = fact_value*(n-i) 
    enddo
end function fact 
