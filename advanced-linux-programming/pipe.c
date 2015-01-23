#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void writer(const char* message, int count, FILE* stream){
	for(;count > 0; --count){
		fprintf(stream,"%s\n", message);
		fflush(stream);
		sleep(1);
	}
}
void reader(FILE* stream){
	char buffer[1024];
	while(!feof(stream) && !ferror(stream)
		  && fgets(buffer,sizeof(buffer),stream) != NULL){
		fputs(buffer,stdout);
	}
}
int main(int argc, char *argv[])
{
    int fds[2],read_fd,write_fd;
	pid_t pid;
	/* Create a pile. File descriptors for the two ends of the pipe are place in fds. */
	pipe(fds);
	read_fd = fds[0];
	write_fd = fds[1];
	/* Fork a child process. */
	pid = fork();
	if(pid != 0 ){
		/* Parent process */
		FILE* stream;
		close(read_fd);
		stream = fdopen(write_fd, "w");
		writer("Hello中国.",5, stream);
		close(write_fd);
	}
	else{
		/* Child process */
		FILE* stream;
		close(write_fd);
		stream = fdopen(read_fd, "r");
		reader(stream);
		close(read_fd);
	}
    return 0;
}
