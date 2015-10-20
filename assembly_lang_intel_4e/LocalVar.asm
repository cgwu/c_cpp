TITLE 局部变量
include Irvine32.inc
.data
	
.code
main PROC
	mov eax,1
	mov ebx,2
	mov ecx,3
	call SumOf
	call WriteInt
	exit
main ENDP

SumOf PROC
	LOCAL tempSum: DWORD, swapFlag: BYTE		;局部变量
	LOCAL array1[10]: DWORD
	;push ebp
	;mov ebp, esp
	;add esp, -4
	mov tempSum, eax
	add tempSum, ebx
	add tempSum, ecx
	mov eax, tempSum
	;leave (LEAVE Set ESP to EBP, then pop EBP)
	ret
SumOf ENDP

end main