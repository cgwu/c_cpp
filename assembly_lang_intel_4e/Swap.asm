TITLE 交换两个WORD数
include Irvine32.inc

Swap PROTO,
	pValX: PTR DWORD,
	pValY: PTR DWORD

.data
	Array DWORD 1000h, 2000h
.code
main PROC
	mov esi, offset array
	mov ecx, 2
	mov ebx, type array
	call DumpMem			;显示内存内容
	
	INVOKE Swap, addr array, addr [array+4]
	
	call DumpMem			;显示内存内容
	exit
main ENDP

Swap PROC USES eax esi edi,
	pValX: PTR DWORD,
	pValY: PTR DWORD
	
	mov esi, pValX
	mov edi, PValY
	mov eax, [esi]
	xchg eax, [edi]
	mov [esi], eax
	ret
Swap ENDP

end main