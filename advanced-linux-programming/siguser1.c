#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
sig_atomic_t siguser1_count = 0;
void handler(int signal_number){
	++siguser1_count;
}
int main(int argc, char *argv[])
{
    struct sigaction sa;
	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = &handler;
	sigaction(SIGUSR1,&sa, NULL);
	system("date");
	int i = 0;
	for(;i<20;i++){
		sleep(1);
	}
	//sleep(20);
	system("date");
	printf("SIGUSER1 was raised %d times\n", siguser1_count);
    return 0;
}
/*
Shell命令发送信号:
查看进程ID: {pid}
$ps -C a.out
给进程发送信号
$kill -s SIGUSR1 {pid}
 */
