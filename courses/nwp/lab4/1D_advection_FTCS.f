! FTCS scheme is unstable 
program adv

        implicit none

        real , parameter :: c = 0.1     ! cm/s
        real , parameter :: dx = 0.05    ! cm
        real , parameter :: dt = .5    ! s
        real , parameter :: l = 3      ! cm max length

        integer , parameter :: M = l/dx + 1     ! number of space grids
        integer , parameter :: N = 200           ! number of time steps 

        integer , parameter :: fn = 1           ! file number 
        real :: U(M) , Un1(M)
        real :: x(M)            ! array for x axis
        integer :: i , j 
        real :: r
        
        do i = 1,M
                U(i) = 0.75*exp(-(((i-1)*dx-0.5)/0.1)**2)
                Un1(i) = 0 
                x(i) = dx*(i-1)
        end do


        ! checking the initial conditions
        open(unit = fn , file = "temp.dat") 
        do i = 1,M               
                write(fn,*) x(i),U(i)
        end do
        close(fn)
        call system('gnuplot -p gnuplot.plt')
      
        r = c*dt/dx

        do j = 1,N
                open(unit = fn , file = "temp.dat") 
                
                
                !!!!! Mirroring is beign done at first and last grid point !!!!!
                Un1(1) = U(1) - (U(1+1)-U(M))*r/2
                write(fn,*) x(1) , Un1(1)
                do i = 2,M-1
                       Un1(i) = U(i) - (U(i+1)-U(i-1))*r/2
                       write(fn,*) x(i),Un1(i)
                end do
                Un1(M) = U(M) - (U(1)-U(M-1))*r/2
                write(fn,*) x(M),Un1(M)
                close(fn)
                U = Un1
                call system('gnuplot -p gnuplot.plt')
                call system('sleep 0.06')
        end do 


end program adv
