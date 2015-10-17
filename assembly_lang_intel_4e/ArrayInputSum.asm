TITLE  整数输入及求和
include Irvine32.inc

IntegerCount = 3

.data
	prompt1 BYTE "输入一个有符号整数:",0
	prompt2 BYTE "数组和为:",0
	array 	DWORD IntegerCount DUP(?)
.code
main PROC
	call ClrScr
	mov esi, OFFSET array
	mov ecx, IntegerCount
	call PromptForIntegers
	call ArraySum
	call DisplaySum
	exit
main ENDP

;读取整数并保存
PromptForIntegers PROC
	PUSHAD
	MOV edx, OFFSET prompt1
L1:
	call WriteString
	call ReadInt
	mov [esi], eax		;保存到数组
	add esi, 4
	loop L1
	
	popad
	ret
PromptForIntegers ENDP

ArraySum PROC uses esi ecx
	mov eax,0
L1:
	add eax, [esi]
	add esi, 4
	loop L1
	
	ret
ArraySum ENDP

DisplaySum PROC uses edx
	mov edx, offset prompt2
	call WriteString
	call WriteInt		; 显示eax
	call Crlf
	ret
DisplaySum ENDP
end main