! BTCS scheme for Heat conduction equation (1D) using Thomas Algorithem
program BTCS_conduction

    implicit none 
    
    real , parameter :: K = 4 
    real , parameter :: L = 10 
    real , parameter :: T = 10 
    integer , parameter :: M = 25       ! Size of X dim array
    integer , parameter :: N = 44 
    
    integer , parameter :: fn = 1 
    real , parameter :: dx = L/(M-1) 
    real , parameter :: dt = T/(N-1)
    real , parameter :: r  = K*dt/dx**2 
    real , parameter :: pi = atan(1.0)*4
    real :: x(M) , Tn(M) , Tn1(M) , cd(M-2) , dd(M-2) , d(M-2)
    integer :: i , j 
    real :: a = -r , b = (2*r+1) , c = -r      

    call system('gnuplot dynamic.plt &')
    Tn1 = Tn1*0
    
    do j = 1,size(Tn)
        x(j) = (j-1)*dx
        !Tn = sin(pi*x/l)
    end do
    Tn = sin(pi*x/l)

    Tn(size(Tn)) = 0

    open(unit = fn,file = "temp.dat")
    do i = 1,M
        write(fn,*) x(i),Tn(i)
    end do
    close(fn)
    call sleep(1)
    !print*, x , Tn

    cd(1) = c/b
    do i = 2,size(cd)
        cd(i) = c/(b-(a*cd(i-1)))
    end do

    do j = 1 , N
        
        open(unit = fn, file = "temp.dat")

        d = Tn(2:(size(Tn)-1))
        
        dd(1) = d(1)/b 
        do i = 2,size(dd)
            dd(i) = (d(i) - (a*dd(i-1)))/(b-(a*cd(i-1)))
        end do
        
        write(fn,*) x(size(dd)+2),Tn1(size(dd)+2)

        Tn1(size(dd)+1) = dd(size(dd))
        write(fn,*) x(size(dd)+1),Tn1(size(dd)+1)
        
        do i =  int(size(dd)-1) , 1 , -1
            Tn1(i+1) = dd(i) - cd(i)*Tn1(i+1+1)
            write(fn,*) x(i+1),Tn1(i+1)
        end do
        write(fn,*) x(1),Tn1(1)

        Tn = Tn1

        close(fn)

        call system('sleep 0.1')
        
    end do
    

end program BTCS_conduction

