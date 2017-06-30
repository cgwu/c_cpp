#include <signal.h>
#include <stdio.h>
#include <unistd.h>
void ouch(int sig){
    printf("OUCH! - I got signal %d\n", sig);
    (void) signal(SIGINT, SIG_DFL);
}
int main(int argc, const char *argv[])
{
    (void) signal(SIGINT, ouch);
    while(1) {
        printf("Hello 中国\n");
        sleep(1);
    }
    return 0;
}
