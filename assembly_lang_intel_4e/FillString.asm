TITLE ����ַ���
include Irvine32.inc
.data
	
.code

FillString PROC uses eax esi
	LOCAL string[21]: byte
	lea esi, string				; ����ʱȡ��ַ load effective address
	;mov esi, offset string		; ����ʱȡ��ַ
	mov ecx, 20
L1:
	mov eax, 10
	call RandomRange			; AL = 0..9
	add al, 30h					; convert to ASCII character
	mov [esi],al
	inc esi
	loop L1
	mov byte ptr [esi],12h
	mov byte ptr [esi],0
	
	lea edx, string
	call WriteString	;����ַ���
	
	lea esi, string
	mov ecx, 21
	mov ebx, 1		
	call DumpMem		;����ڴ�
	ret
FillString ENDP

main PROC
	call FillString
	exit
main ENDP



end main