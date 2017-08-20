#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc, const char *argv[])
{
    int fd;
    if((fd = open("/dev/dsp", O_WRONLY)) < 0) {
        printf("errno = %d\n", errno);
        char *msg = strerror(errno);
        printf("msg: %s\n", msg);
    }
    exit(0);
    return 0;
}
