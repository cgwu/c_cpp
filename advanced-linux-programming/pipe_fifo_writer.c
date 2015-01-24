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
void writer(const char* message, int count, FILE* stream){
	for(;count > 0; --count){
		fprintf(stream,"%s\n", message);
		fflush(stream);
		sleep(1);
	}
}
int main(int argc, char *argv[])
{
	FILE *pipe;
	pipe = fopen(fifo_path,"w");
	writer("Hello中国.",5,pipe);
	fclose(pipe);	
    return 0;
}
