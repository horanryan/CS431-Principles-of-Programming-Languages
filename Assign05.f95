!Ryan Horan
!December 2, 2022
!Fortran95 
!selection sort and quicksort
!Used https://www.mjr19.org.uk/IT/sorts/sorts.f90 for the qsort
!used https://www.geeksforgeeks.org/selection-sort/ for the selection
!Plato 64 bit
program sort

integer, dimension(100) :: unsorted


open(15 ,file = "random_numbers.txt" )
do j= 1,100
read(15,*)(unsorted(j))
end do

close(12)

call select_sort(unsorted)

do i = 1,100
  print*, unsorted(i)
 end do
print*, ''
call qsort(unsorted)
do i = 1,100
  print*, unsorted(i)
 end do

end program sort

subroutine select_sort(sorted)
integer, dimension(100) :: sorted
integer :: temp
integer :: i,j,k
do i = 1,size(sorted)-1
  temp = sorted(i)
  j=i
  do k=i+1,size(sorted)
    if(sorted(k).lt.temp) then
      temp = sorted(k)
      j=k
      endif
     enddo
   sorted(j)=sorted(i)
   sorted(i) = temp
  enddo
 
 end subroutine

 recursive subroutine qsort(qsorted)
 integer, dimension(100) :: qsorted
 integer :: temp,pivot
 integer :: i,j,last,left,right
 last = size(qsorted)

 if(last.lt.50) then
   do i=2,last
     temp=qsorted(i)
     do j=i-1,1,-1
       if(qsorted(j).le.temp)exit
         qsorted(j+1) = qsorted(j)
         enddo
          qsorted(j+1)=temp
       enddo
       return
    endif
    
    temp=qsorted(last/2)
    qsorted(last/2)=qsorted(2)
    if (temp.gt.qsorted(last)) then
       qsorted(2)=qsorted(last)
       qsorted(last)=temp
    else
       qsorted(2)=temp
    endif
    if (qsorted(1).gt.qsorted(last)) then
       temp=qsorted(1)
       qsorted(1)=qsorted(last)
       qsorted(last)=temp
    endif
    if (qsorted(1).gt.qsorted(2)) then
       temp=qsorted(1)
       qsorted(1)=qsorted(2)
       qsorted(2)=temp
    endif
    pivot=qsorted(2)

    left=3
    right=last-1
    do
       do while(qsorted(left).lt.pivot)
          left=left+1
       enddo
       do while(qsorted(right).gt.pivot)
          right=right-1
       enddo
       if (left.ge.right) exit
       temp=qsorted(left)
       qsorted(left)=qsorted(right)
       qsorted(right)=temp
       left=left+1
       right=right-1
    enddo
    if (left.eq.right) left=left+1
    call qsort(qsorted(1:left-1))
    call qsort(qsorted(left:))

  end subroutine qsort