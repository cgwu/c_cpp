#include "apue.h"
#include <errno.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    fprintf(stderr, "EACCESS: %S\n", strerror(EACCES));
    errno = ENOENT;
    perror(argv[0]);
    printf("done\n");
    exit(0);
}
