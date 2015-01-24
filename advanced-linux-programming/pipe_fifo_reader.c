/*
使用Shell测试named pipe:
1.在第一个Shell中运行:
  mkfifo /tmp/fifo
  ls -l /tmp/fifo
  cat < /tmp/fifo
2.第二个shell中
  cat > /tmp/fifo
  再输入内容按回车，在第一个shell中就会显示出内容，
  按Ctrl+d结束.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
static char* fifo_path = "/tmp/fifo";

void reader(FILE* stream){
	char buffer[1024];
	while(!feof(stream) && !ferror(stream)
		  && fgets(buffer,sizeof(buffer),stream) != NULL){
		fputs(buffer,stdout);
	}
}

int main(int argc, char *argv[])
{
	FILE *pipe;
    if(mkfifo(fifo_path,0777) == -1){
		perror("Cannot create FIFO channel.\n");
		return 1;
	}
	pipe = fopen(fifo_path,"r");
	reader(pipe);
	fclose(pipe);	
    return 0;
}
