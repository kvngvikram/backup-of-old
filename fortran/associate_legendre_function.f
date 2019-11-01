program alf

    implicit none 


    integer :: n=5,m=1,i
    real :: x=0.34,dfact,fact
    real :: bla = 16
    


    
    !print*, n,m
    x = n
    !print*,'x is', x  
    !do i=2,n,2
    !    print*,'i is ', i
    !    x = x*(n-i) 
    !    print*, x 
    !enddo

    print*, 'dfact is',dfact(7)
    print*, 'sqrt is ',sqrt(bla)
    print*, 'sin is', sin(real(90))
    print*, 'fact valule is ',fact(4)
    print*, 'xvalue is ',x
    
    do i=1,n
        print*, 'i value is ',i
    enddo 

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
        print*,'i is ', i
        fact_value = fact_value*(n-i) 
        print*, 'fact value in funct ', fact_value
    enddo
end function fact 
