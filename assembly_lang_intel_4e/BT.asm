TITLE BTָ�� bit test
include Irvine32.inc
.data
	semaphore word 00001000b
.code
main PROC
	bt semaphore, 3		;����3λ�ƶ���CF��־
	btc semaphore, 4	;����4λ�ƶ���CF��־,������λȡ��
	btr semaphore, 4	;����4λ�ƶ���CF��־,������λ��0��bit test reset
	bts semaphore, 5	;����4λ�ƶ���CF��־,������λ����1��bit test set
	exit
main ENDP



end main