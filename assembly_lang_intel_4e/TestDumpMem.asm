
TITLE ≤‚ ‘DumpMem
include Irvine32.inc
.data
array DWORD 1,2,3,4,5,6,7,8,9,0AH,010BH

.code
main PROC
	mov esi, OFFSET array
	mov ecx, LENGTHOF array
	mov ebx, TYPE array
	call DumpMem
	call DumpRegs
	
	mov ebx, 2
	mov ecx, LENGTHOF array
	add ecx, ecx
	call DumpMem
	call DumpRegs
	
	exit
main endp
end main