TITLE 按值传递或按引用传递
include Irvine32.inc
.data
	myData WORD 1000h
.code

SubByValue PROC someData: WORD
	mov someData, 1
	ret
SubByValue ENDP

SubByRef PROC dataPtr: PTR WORD
	MOV esi, dataPtr
	mov word ptr [esi], 2
	ret
SubByRef ENDP

main PROC
	INVOKE SubByValue, myData
	nop
	nop
	INVOKE SubByRef, ADDR myData
	nop
	nop
	exit
main ENDP

end main