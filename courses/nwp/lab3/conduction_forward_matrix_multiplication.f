program myprogram 

        implicit none

        real , parameter :: l = 10 
        real , parameter :: t = 10
        real , parameter :: K = 4
        integer , parameter :: M = 50
        integer , parameter :: N = 2001 
        integer , parameter :: fn1 = 1 , fn2 = 2  ! are the file numbers and should not be 6
        real , parameter :: pi = atan(1.0)*4
        real :: Tn(M) , Tn1(M) , A(M,M) , Anl_T(M) 
        real :: dx , dt , r 
        real :: Bl , Br 
        integer :: i , j  , g   ! these will be used as the loop variables

        dx = l/real(M-1)
        dt = t/real(N-1)
        r = K*dt/dx**2

        do j = 1,int(M)
        !        Tn(i) = 0 
                Tn1(j) = 0
        !        print*, Tn1(j), j  
        end do
        


        do j = 1,int(M)
                Tn(j) = sin(pi*float(j-1)*dx/l)
                !print*, Tn(j) , j
        end do
        Bl = 0 
        Br = 0 

        ! Defining the Coefficient matrix A 

        ! First row
        A(1,1) = Bl
        do i = 2 , M
                A(1,i) = 0 
        end do
        
        ! Second row
        A(2,1) = r 
        A(2,2) = -(2*r-1)
        A(2,3) = r 
        do i = 4 , M 
                A(2,i) = 0
        end do
        
        ! For the first column
        do i = 3 , M
                A(i,1) = 0 
        end do

        ! For the rows between except the first column 
        do i = 3 , M-1            ! for rows 
                do j = 2 , M    ! for columns 
                        A(i,j) = A(i-1,j-1)
                end do 
        end do 

        ! For last row
        do i = 1,M-1
                A(M,i) = 0
        end do
        A(M,M) = Br

        ! Marching in time 
        do g = 1 ,  N
                
                open(unit = fn1 , file = "temp1.dat")

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

                do i = 1 , M

                        Tn1(i) = 0
                        do j = 1 , M
                        
                                Tn1(i) = Tn1(i) + A(i,j)*Tn(j)

                        end do
                        write(fn1,*) (i-1)*dx , Tn1(i)
                end do
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                close(fn1)
                
                open(unit = fn2 , file = "temp2.dat")
                do i = 1 , M
                        Anl_T(i) = exp(-K*((pi/l)**2)*((g-1)*dt))*sin((i-1)*dx*pi/l)
                        write(fn2,*) (i-1)*dx , Anl_T(i) - Tn1(i)
                end do
                close(fn2)
                
                call system('gnuplot -p gnuplot.plt')
                call system('sleep  0.06')

                Tn = Tn1
        end do
        
        call system('rm temp1.dat') 
        call system('rm temp2.dat')

end program myprogram

