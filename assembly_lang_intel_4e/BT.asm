TITLE BT指令 bit test
include Irvine32.inc
.data
	semaphore word 00001000b
.code
main PROC
	bt semaphore, 3		;将第3位移动到CF标志
	btc semaphore, 4	;将第4位移动到CF标志,并将该位取反
	btr semaphore, 4	;将第4位移动到CF标志,并将该位清0，bit test reset
	bts semaphore, 5	;将第4位移动到CF标志,并将该位设置1，bit test set
	exit
main ENDP



end main