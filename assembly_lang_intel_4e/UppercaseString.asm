TITLE 将字符串转为大写
include Irvine32.inc
.data
	msg byte "HelloWorldWelcome",0
.code
main PROC
	mov ecx, lengthof msg
	mov esi, offset msg
	mov edx, esi
	call WriteString
	;转为大写
L1:	
	; test 指令与and指令唯一差别，不影响目的操作数
	and byte ptr [esi],11011111b	
	inc esi
	loop L1
	
	call Crlf
	call WriteString
	
	mov ecx, lengthof msg
	mov esi, offset msg
	;转为小写
L2:	
	or byte ptr [esi],00100000b
	inc esi
	loop L2
	
	call Crlf
	call WriteString
	
	exit
main ENDP



end main