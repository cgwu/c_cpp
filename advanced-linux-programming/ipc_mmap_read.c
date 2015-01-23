#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#define FILE_LENGTH 0x100

int main(int argc, char *argv[])
{
	int fd;
	void* file_memory;
	int integer;

	/* Prepare a file large enough to hold an unsigned integer. */
	fd = open(argv[1], O_RDWR, S_IRUSR | S_IWUSR);
	/* Create the memory mapping. */
	file_memory = mmap(0,FILE_LENGTH, PROT_READ | PROT_WRITE, MAP_SHARED, fd,0);
	close(fd);
	/* Read the integer, print it out, and double it. */
	sscanf(file_memory, "%d", &integer);
	printf("value:%d\n", integer);
	/* Write a random integer to memory-mapped area. */
	sprintf((char*) file_memory, "%d\n", 2 * integer);
	//	sprintf((char*) file_memory, "%d\n", 345);
	munmap(file_memory, FILE_LENGTH);	
	return 0;
}
