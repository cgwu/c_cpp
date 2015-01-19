#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    pid_t child_pid;
	printf("主进程ID:%d\n",(int)getpid());
	child_pid = fork();
	if(child_pid != 0){
		//主进程
		printf("这里是主进程，新的子进程ID为:%d\n",(int)child_pid);
		sleep(1);
	}
	else{
		printf("这里是子进程，父进程ID为%d,当前进程ID为:%d\n",(int)getppid(),(int)getpid());
	}
	printf("%d结束\n",(int)getpid());
    return 0;
}
