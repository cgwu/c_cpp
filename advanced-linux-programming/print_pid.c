#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    printf("当前进程ID:%d\n",(int)getpid());
	printf("当前父进程ID:%d\n",(int)getppid());	
    return 0;
}
