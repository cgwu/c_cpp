TITLE ���ݶ�ջ�����͹��̼��������
include Irvine32.inc
.data
	array DWORD 1,2,3,4,5,6,7,8,9
	theSum DWORD ?
.code

;����ԭ����ǰ����, Ĭ��Ϊstdcall,�������߻ָ�ջ��ָ��
ArraySum PROTO,
	ptrArray: PTR DWORD,		; ����:����ָ��
	szArray: DWORD				; ����:���鳤��
	
main PROC
	INVOKE ArraySum,
		ADDR array,
		LENGTHOF array
	mov theSum, eax
	call WriteInt
	exit
main ENDP

ArraySum PROC USES esi ecx,
	ptrArray: PTR DWORD,		; ����:����ָ��
	szArray: DWORD				; ����:���鳤��

	mov ecx, szArray
	mov esi, ptrArray
	cmp ecx, 0
	je L2
	mov eax, 0
L1:
	add eax, [esi]
	add esi, 4
	loop L1
L2:
	ret
ArraySum ENDP
end main
