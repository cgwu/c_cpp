TITLE 
;.if condition1
;	statements
;.elseif contition2
;	statements
;.else
;	statements
;.endif
include Irvine32.inc
.data
	val1 sdword 5
	result dword ?
.code
main PROC
	mov eax, 6
	.if eax > val1
		mov result, 1
	.endif
	exit
main ENDP



end main