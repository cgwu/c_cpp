#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
int main(int argc, char *argv[])
{
    printf("argc=%d\n",argc);
	if(argc > 1){
		pid_t pid = atoi(argv[1]);
		printf("kill pid=%d\n",pid);
		kill(pid,SIGKILL);  //向指定的进程发送信号
	}
    return 0;
}
