TITLE  �������뼰���
include Irvine32.inc

IntegerCount = 3

.data
	prompt1 BYTE "����һ���з�������:",0
	prompt2 BYTE "�����Ϊ:",0
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

;��ȡ����������
PromptForIntegers PROC
	PUSHAD
	MOV edx, OFFSET prompt1
L1:
	call WriteString
	call ReadInt
	mov [esi], eax		;���浽����
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
	call WriteInt		; ��ʾeax
	call Crlf
	ret
DisplaySum ENDP
end main