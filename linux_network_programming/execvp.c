#include <stdio.h>
#include <unistd.h>
int main(){
    printf("Test execvp...\n");
    char *av[] = {"ls","-l",NULL};
    execvp(av[0],av);
    // 如果execv返回，说明调用失败
    perror("execv failed to run cmd");
    return 1;
}

