TITLE �޷������з��ŵıȽ�
include Irvine32.inc
.data
	
.code
main PROC
	mov al, 80h
	cmp al, 7fh
	jg IsGreater	;�з��űȽ�
	mov eax,1
	nop
	nop
	ja IsAbove		;�޷��űȽ�
	mov eax,2
	nop
	nop
	nop
IsAbove:
	mov eax,3
	nop
	nop
	nop
IsGreater:
	mov eax,4
	exit
main ENDP



end main