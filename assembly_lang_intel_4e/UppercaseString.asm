TITLE ���ַ���תΪ��д
include Irvine32.inc
.data
	msg byte "HelloWorldWelcome",0
.code
main PROC
	mov ecx, lengthof msg
	mov esi, offset msg
	mov edx, esi
	call WriteString
	;תΪ��д
L1:	
	; test ָ����andָ��Ψһ��𣬲�Ӱ��Ŀ�Ĳ�����
	and byte ptr [esi],11011111b	
	inc esi
	loop L1
	
	call Crlf
	call WriteString
	
	mov ecx, lengthof msg
	mov esi, offset msg
	;תΪСд
L2:	
	or byte ptr [esi],00100000b
	inc esi
	loop L2
	
	call Crlf
	call WriteString
	
	exit
main ENDP



end main