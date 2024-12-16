		integer(kind=8) :: evnt, mul, temp
		real(kind=8) :: rap
		open(unit=1,file="output.dat")
		open(unit=2,file="pp-13t-cc-full.dat")
3		read(1,*,iostat=ios) evnt, mul
		if(ios.ne.0) goto 15
		write(2,5) evnt, mul
5		format(I6,4x,I7)		
		do i=1,mul
		  read(1,*) temp, rap
		  write(2,10) temp, rap
		enddo
10		format(I6,4X,F7.3)
		goto 3
15		close(1)
		write(*,*) "Thank You..."		
		stop
		end
		  
