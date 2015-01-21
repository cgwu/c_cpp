#include <pthread.h>
#include <stdio.h>
#include <malloc.h>

typedef struct __Arg{
	int x,y;
} Arg, *PArg;

void* run_add(void* pa){
	PArg p = (PArg) pa;
	/*
	int c = p->x + p->y;
	return (void*)c;
	*/
	int *pResult = (int*)malloc(sizeof(int));
	*pResult = p->x + p->y;
	return (void*)pResult;
}

int main(int argc, char *argv[])
{
    pthread_t thread1_id;
	Arg a;
	//int result = 0;
	int *pret = NULL;
	a.x = 11;
	a.y = 22;
	pthread_create(&thread1_id,NULL,run_add,&a);
	//	pthread_join(thread1_id,(void*)&result);
	//	printf("线程返回的值为%d\n",result);
	pthread_join(thread1_id,(void*)&pret);
	if(pret != NULL){
		printf("线程返回的值为%d\n",*pret);
		free(pret);
	}
    return 0;
}
