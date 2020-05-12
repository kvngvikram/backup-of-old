! CTCS scheme is conditionally stable
! Computational mode should be damped 
program adv

        implicit none

        real , parameter :: c = 0.1     ! cm/s
        real , parameter :: dx = 0.05    ! cm
        real , parameter :: dt = .25    ! s
        real , parameter :: l = 3      ! cm max length

        integer , parameter :: M = l/dx + 1     ! number of space grids
        integer , parameter :: N = 200           ! number of time steps 

        integer , parameter :: fn = 1           ! file number 
        real :: Un(M) , Unp1(M) , Unm1(M)
        real :: x(M)            ! array for x axis
        integer :: i , j 
        real :: r
        
        call system('gnuplot dynamic.plt &')
        
        ! Initial conditions also showing
        open(unit = fn , file = "temp.dat")
        do i = 1,M
                Unm1(i) = 0.75*exp(-(((i-1)*dx-0.5)/0.1)**2)
                Un(i) = 0
                Unp1(i) = 0  
                x(i) = dx*(i-1)
                write(fn,*) x(i),Unm1(i)
        end do
        close(fn)
        
      
        r = c*dt/dx

        !!!!! First step will be FTCS
        open(unit = fn , file = "temp.dat") 
        
        !!!!! Mirroring is beign done at first and last grid point !!!!!
        Un(1) = Unm1(1) - (Unm1(1+1)-Unm1(M))*r/2
        write(fn,*) x(1) , Un(1)
        do i = 2,M-1
               Un(i) = Unm1(i) - (Unm1(i+1)-Unm1(i-1))*r/2
               write(fn,*) x(i),Un(i)
        end do
        Un(M) = Unm1(M) - (Unm1(1)-Unm1(M-1))*r/2
        write(fn,*) x(M),Un(M)
        close(fn)


        !!!!! Doing CTCS
        do j = 1,N
                open(unit = fn , file = "temp.dat") 
                
                !!!!! Mirroring is beign done at first and last grid point !!!!!
                Unp1(1) = Unm1(1) - (Un(1+1)-Un(M))*r
                write(fn,*) x(1) , Unp1(1)
                do i = 2,M-1
                       Unp1(i) = Unm1(i) - (Un(i+1)-Un(i-1))*r
                       write(fn,*) x(i),Unp1(i)
                end do
                Unp1(M) = Unm1(M) - (Un(1)-Un(M-1))*r
                write(fn,*) x(M),Unp1(M)
                close(fn)
                Unm1 = Un
                Un = Unp1
                
             !   call system('gnuplot dumb.plt')                
                call system('sleep 0.01')
        end do 


end program adv
