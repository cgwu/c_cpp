TITLE ��ת�ַ���
include Irvine32.inc
.data
	aName BYTE "Abraham Lincoln", 0
	nameSize = ($ - aName) - 1
.code
main PROC
	;������ѹ��ջ
	mov ecx, nameSize
	mov esi, 0
L1:
	movzx eax, aName[esi]
	push eax
	inc esi
	loop L1
	
	mov ecx, nameSize
	mov esi,0
	
	;��ջ
L2:
	pop eax
	mov aName[esi], al
	inc esi
	loop L2
	;��ʾ�ַ���
	mov edx, OFFSET aName
	call WriteString
	call Crlf

	exit
main endp
end main