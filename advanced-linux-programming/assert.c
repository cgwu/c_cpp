#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <errno.h>
int add(int a, int b){
	assert(a>0 && b>0);
	return a+b;
}
int main(int argc, char *argv[])
{
    int c = add(1,2);    // gcc -DNDEBUG assert.c 编译时，将换略此宏
	printf("c=%d\n",c);

	int fd = open("file_not_exit.txt",O_RDONLY);
	if(fd==-1){
		fprintf(stderr,"error opening file: code:%d; msg:%s\n",errno, strerror(errno));
		exit(1);
	}
    return 0;
}
