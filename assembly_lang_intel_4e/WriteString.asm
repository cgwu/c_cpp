TITLE ����ַ���
include Irvine32.inc
.data
prompt BYTE  "�������name:",0

.code
main PROC
	mov edx, OFFSET prompt
	call WriteString
	exit
main endp
end main