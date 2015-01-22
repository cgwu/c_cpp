#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>

// The key used to associate a log file pointer with each thread
static pthread_key_t thread_log_key;

void write_to_thread_log(const char* message){
	FILE* thread_log = (FILE*) pthread_getspecific(thread_log_key);
	fprintf(thread_log, "pid[%d],thread_id[%d]:%s\n",(int)getpid(),(int)pthread_self(),message);
}
void close_thread_log(void* thread_log){
	fclose((FILE*)thread_log);
}
void* thread_function(void* args){
	char thread_log_filename[20];
	FILE* thread_log;
	sprintf(thread_log_filename,"thread-%d.log",(int)pthread_self());
	thread_log = fopen(thread_log_filename,"w");
	pthread_setspecific(thread_log_key,thread_log);    //设置线程本地变量，相当于Java中的ThreadLocal
	write_to_thread_log("线程开始");
	return NULL;
}
int main(int argc, char *argv[])
{
    int i;
	pthread_t thread[5];
	pthread_key_create(&thread_log_key, close_thread_log);
	for(i=0;i<5;++i){
		pthread_create(&thread[i], NULL,thread_function,NULL);
	}
	for(i=0;i<5;++i){
		pthread_join(thread[i],NULL);
	}
	printf("done\n");
    return 0;
}
