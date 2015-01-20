#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

sig_atomic_t child_exit_status;

void clean_up_child_process(int signal_number){
	/* Clean up the child process. */
	int status;
	wait(&status);
	child_exit_status = status;
}

int main(int argc, char *argv[])
{
	struct sigaction sigchld_action;
	memset(&sigchld_action, 0, sizeof(sigchld_action));
	sigchld_action.sa_handler = &clean_up_child_process;
	sigaction(SIGCHLD, &sigchld_action, NULL);
	
    pid_t child_pid;
	child_pid = fork();
	if(child_pid>0){
		/* 这里是主进程 */
		//sleep(30);
		int i=0;
		for(;i<10;i++){
			fprintf(stderr,"%d\t",i);
			sleep(1);
		}
	}
	else{
		/* 这里是子进程,立即退出，此时它变成了僵尸进程
		   A zombie process is a process that has terminated but has not been cleaned up yet.
		 */
		int i=0;
		for(;i<5;i++){
			fprintf(stderr,"子%d\t",i);
			sleep(1);
		}
		printf("子进程[pid=%d,ppid=%d]完成\n",getpid(),getppid());
		exit(0);
	}
	printf("主进程[pid=%d,ppid=%d]完成\n",getpid(),getppid());
    return 0;
}
