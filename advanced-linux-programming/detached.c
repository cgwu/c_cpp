#include <pthread.h>
#include <stdio.h>
void* thread_function(void* thread_arg){
	int i=0;
	for(;i<10;i++){
		fprintf(stderr,"thread_id:[%d]; %d\t",pthread_self(),i);
	}
	return NULL;
}
int main(int argc, char *argv[])
{
    pthread_attr_t attr;
	pthread_t thread;

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	pthread_create(&thread,&attr,&thread_function,NULL);
	pthread_attr_destroy(&attr);
	sleep(1);
	printf("Main完成.\n");
    return 0;
}
