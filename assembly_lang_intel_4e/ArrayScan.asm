TITLE ษจร่สýื้
include Irvine32.inc
.data
	intArray sword 0,0,0,0,1,20,35,-12,66,4,-13
	noneMsg byte "not found",0
.code
main PROC
	mov ebx, offset intArray
	;lea ebx, intArray
	mov ecx, lengthof intArray
L1:
	;cmp word ptr [ebx], 0
	;jnz found
	cmp word ptr [ebx], -13
	jz found
	add ebx, 2
	loop L1
	jmp notFound
found:
	movsx eax, word ptr[ebx]
	call WriteInt
	jmp quit
notFound:
	mov edx, offset noneMsg
	call WriteString
quit:
	call Crlf
	exit
main ENDP



end main