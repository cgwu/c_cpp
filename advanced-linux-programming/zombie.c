#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    pid_t child_pid;
	child_pid = fork();
	if(child_pid>0){
		/* 这里是主进程 */
		sleep(30);
	}
	else{
		/* 这里是子进程,立即退出，此时它变成了僵尸进程
		   A zombie process is a process that has terminated but has not been cleaned up yet.
		 */		
		exit(0);
	}
	printf("[pid=%d,ppid=%d]完成\n",getpid(),getppid());
    return 0;
}
