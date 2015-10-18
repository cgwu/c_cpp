TITLE 扫描数组直到发现正数
include Irvine32.inc
.data
	array sword -3,-6,-1,-10,100,30,40,4
	
.code
main PROC
	lea esi, array
	mov ecx, lengthof array
next:
	test word ptr [esi], 8000h
	pushfd
	add esi, type array
	popfd
	loopnz next
	
	jnz quit
	sub esi, type array
	movzx eax, word ptr [esi]
	call WriteInt
	call Crlf
quit:
	exit
main ENDP



end main