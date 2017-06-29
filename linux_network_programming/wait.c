/*
#include <sys/types.h>
#include <sys/wait.h>

pid_t wait(int *stat_loc);

Macro                   Definition
WIFEXITED(stat_val)     Nonzero if the child is terminated normally.
WEXITSTATUS(stat_val)   If WIFEXITED is nonzero, this returns child exit code.
WIFSIGNALED(stat_val)   Nonzero if the child is terminated on an uncaught signal.
WTERMSIG(stat_val) If   WIFSIGNALED is nonzero, this returns a signal number.
WIFSTOPPED(stat_val)    Nonzero if the child has stopped.
WSTOPSIG(stat_val) If   WIFSTOPPED is nonzero, this returns a signal number.
*/
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
    pid_t pid;
    char *message;
    int n;
    int exit_code;

    printf("fork program starting\n");
    pid = fork();
    switch(pid){
    case -1:
        perror("fork failed");
        exit(1);
    case 0:
        message = "This is the child";
        n = 3;
        exit_code = 37;
        break;
    default:
        message = "This is the parent";
        n = 6;
        exit_code = 0;
        break;
    }
    for(;n>0;n--){
        puts(message);
        sleep(1);
    }
    if(pid != 0){
        // 父进程等子进程结束
        int stat_val;
        pid_t child_pid;

        child_pid = wait(&stat_val);
        
        printf("Child has finished: PID = %d\n", child_pid);
        if(WIFEXITED(stat_val))
            printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
        else
            printf("Child terminated abnormally\n");
    }
    exit(exit_code);
//    return 0;
}
