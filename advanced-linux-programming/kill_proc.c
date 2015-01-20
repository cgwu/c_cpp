#include <stdio.h>
//#include <unistd.h>
int main(int argc, char *argv[])
{
    printf("这是主程序,进程ID:%d\n",getpid());
	int i=0;
	for(;i<100;i++){
		fprintf(stderr,"%d\t",i);
		sleep(1);
	}
	printf("done\n");
    return 0;
}
