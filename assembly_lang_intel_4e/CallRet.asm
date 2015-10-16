TITLE 调用子过程
include Irvine32.inc
.data
	
.code
main PROC
	call mySub
	mov eax, ebx
	exit
main endp

mySub PROC
	mov ebx, 1
	ret
mySub ENDP

end main