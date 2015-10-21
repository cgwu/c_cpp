TITLE 填充字符串
include Irvine32.inc
.data
	
.code

FillString PROC uses eax esi
	LOCAL string[21]: byte
	lea esi, string				; 运行时取地址 load effective address
	;mov esi, offset string		; 编绎时取地址
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
	call WriteString	;输出字符串
	
	lea esi, string
	mov ecx, 21
	mov ebx, 1		
	call DumpMem		;输出内存
	ret
FillString ENDP

main PROC
	call FillString
	exit
main ENDP



end main