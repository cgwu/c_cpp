TITLE �������
include Irvine32.inc
.data
	array DWORD 1,2,3,4,5,6,7,8,9
	;arrayLen DWORD ($ - array) / TYPE array		;���鳤��
	sum DWORD ?	
.code
main PROC
	mov esi, offset array
	;mov ecx, arrayLen
	mov ecx, LENGTHOF array		;����2��ֱ��ȡ�����鳤��
	xor eax,eax
	call sumOf
	exit
main endp

sumOf PROC
S1:
	add eax, [esi]
	add esi, 4
	loop S1
	ret
sumOf ENDP

end main