program myprogram 

        implicit none

        real :: l = 10 
        real :: t = 10
        real :: K = 4
        real :: M = 25
        real :: N = 501 
        real :: Tn(25) , Tn1(25)

        integer :: fn = 1 ! is the file number and should not be 6
        real :: dx , dt , r 
        real :: pi = atan(1.0)*4
        
        integer :: i , j 

        dx = l/(M-1)
        dt = t/(N-1)
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


        do i = 1 , int(N)
                
                open(unit = fn , file = "temp.dat")
                
                write(fn,*) 0*dx , Tn1(1)
                do j = 2,int(M)-1
                        
                        Tn1(j) = r*( Tn(j-1) - 2*Tn(j) + Tn(j+1) ) + Tn(j)
                        
                        write(fn,*) (j-1)*dx , Tn1(j)
                end do
                write(fn,*) (M-1)*dx , Tn1(int(M))

                close(fn)
                
                call system('gnuplot gnuplot.plt')
                call system('sleep  0.2')

                Tn = Tn1

        end do
        
!        call system('rm temp.dat') 

end program myprogram

