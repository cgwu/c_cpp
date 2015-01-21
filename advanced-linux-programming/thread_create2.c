#include <pthread.h>
#include <stdio.h>
struct char_print_parms{
	char ch;
	int count;
};
void* print_char(void* pargs){
	struct char_print_parms*  p = (struct char_print_parms*)pargs;
	int i;
	for(i=0;i<p->count;++i){
		fputc(p->ch,stderr);
	}
	return NULL;
}
int main(int argc, char *argv[])
{
    pthread_t thread1_id,thread2_id;
	struct char_print_parms p1,p2;
	p1.ch = 'X';
	p1.count = 3000;
	p2.ch = '0';
	p2.count=2000;
	pthread_create(&thread1_id,NULL,&print_char,&p1);
	pthread_create(&thread2_id,NULL,&print_char,&p2);
	//sleep(2);
	pthread_join(thread1_id,NULL);
	pthread_join(thread2_id,NULL);
	printf("主线程结束\n");
    return 0;
}
