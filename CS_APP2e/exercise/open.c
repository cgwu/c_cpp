#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char *argv[])
{
    int fd1, fd2;

    fd1 = open("foo.txt", O_RDONLY, 0);
    close(fd1);
    fd2 = open("baz.txt", O_RDONLY, 0);
    printf("fd2 = %d\n", fd2);
    exit(0);
    return 0;
}
