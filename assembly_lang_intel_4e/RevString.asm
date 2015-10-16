TITLE 反转字符串
include Irvine32.inc
.data
	aName BYTE "Abraham Lincoln", 0
	nameSize = ($ - aName) - 1
.code
main PROC
	;把名字压入栈
	mov ecx, nameSize
	mov esi, 0
L1:
	movzx eax, aName[esi]
	push eax
	inc esi
	loop L1
	
	mov ecx, nameSize
	mov esi,0
	
	;出栈
L2:
	pop eax
	mov aName[esi], al
	inc esi
	loop L2
	;显示字符串
	mov edx, OFFSET aName
	call WriteString
	call Crlf

	exit
main endp
end main