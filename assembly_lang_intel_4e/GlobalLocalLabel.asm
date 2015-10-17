TITLE 全局标签 和 局部标签
include Irvine32.inc
.data
	
.code
main PROC
	;jmp L2
	call sub2
	mov eax, 01234h
L1::
	exit
main endp

sub2 PROC
L2:
	jmp L1
	ret
sub2 endp

end main