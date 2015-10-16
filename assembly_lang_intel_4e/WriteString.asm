TITLE Êä³ö×Ö·û´®
include Irvine32.inc
.data
prompt BYTE  "ÊäÈëÄãµÄname:",0

.code
main PROC
	mov edx, OFFSET prompt
	call WriteString
	exit
main endp
end main