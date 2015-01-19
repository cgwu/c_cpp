#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int spawn(char *program, char **arg_list){
	pid_t child_pid;
	child_pid = fork();
	if(child_pid != 0){
		nice(19);
		printf("主进程ID:%d\n",getpid());
		//sleep(1);
		//wait(NULL);    /*暂停当前进程的执行，直到有信号来或子进程结束*/
		waitpid(child_pid, NULL,0);  /*暂停当前进程的执行，直到有信号来或指定的子进程结束*/
		return child_pid;
	}
	else{
		printf("主进程ID:%d,子进程ID:%d\n",getppid(),getpid());
		execvp(program, arg_list);
		/* The execvp function returns only if an error occurs. */
		fprintf(stderr, "an error occurred in execvp\n");
		abort();
	}
}
int main(int argc, char *argv[])
{
    char * arg_list[] = {
		"ls",  /*程序名*/
		"-l",
		"/",
		NULL  /*参数列表必须以NULL结束*/
	};
	spawn("ls", arg_list);
	printf("done with main program.\n");
    return 0;
}
