TITLE 根据堆栈参数和过程计算数组和
include Irvine32.inc
.data
	array DWORD 1,2,3,4,5,6,7,8,9
	theSum DWORD ?
.code

;函数原型向前声明, 默认为stdcall,被调用者恢复栈顶指针
ArraySum PROTO,
	ptrArray: PTR DWORD,		; 参数:数组指针
	szArray: DWORD				; 参数:数组长度
	
main PROC
	INVOKE ArraySum,
		ADDR array,
		LENGTHOF array
	mov theSum, eax
	call WriteInt
	exit
main ENDP

ArraySum PROC USES esi ecx,
	ptrArray: PTR DWORD,		; 参数:数组指针
	szArray: DWORD				; 参数:数组长度

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
