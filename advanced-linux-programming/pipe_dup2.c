#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
		fprintf(stream, "This is a test.\n");
		fprintf(stream, "Hello, world.\n");
		fprintf(stream, "My dog has fleas.\n");
		fprintf(stream, "This program is great.\n");
		fprintf(stream, "One fish, two fish.\n");
		fflush(stream);		
		close(write_fd);
		/* Wait for the child process to finish. */
		waitpid(pid,NULL,0);
	}
	else{
		/* Child process */
		close(write_fd);
		/* Connect the read end of the pipe to standard input. */
		dup2(read_fd, STDIN_FILENO);
		/* Replace the child process with the "sort" program. */
		execlp("sort","sort",0);
	}
    return 0;
}
