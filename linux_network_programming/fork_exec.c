#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
int main(int argc, char *argv[]){
    int pid;
    pid = fork();
    switch(pid){
    case -1:
        perror("fork failed");
        return 1;
    case 0:
        execl("/bin/ls", "ls", "-l", "--color", NULL);
        perror("execl failed");
        return 1;
    default :
        wait(NULL);
        printf("ls completed.\n");
        break;
    }
    return 0;
}
