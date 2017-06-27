#include <stdio.h>
#include <unistd.h>
int main(){
    printf("Executing ls\n");
    execl("/bin/ls", "ls", "-lh", NULL);
    // 如果execl返回，说明调用失败
    perror("execl failed to run cmd");
    return 1;
}

