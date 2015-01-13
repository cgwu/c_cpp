#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef int temp_file_handle;

temp_file_handle write_temp_file(char* buff, size_t length){
	char temp_filename[] = "/tmp/temp_file.XXXXXX";
	int fd = mkstemp(temp_filename);
	//Unlink the file immediately, so that it will be removed when the file descriptor is closed
	unlink(temp_filename);    
	write(fd,&length, sizeof(length));
	write(fd,buff,length);
	return fd;
}
char* read_temp_file(temp_file_handle temp_file, size_t* length){
	char* buf;
	int fd = temp_file;
	lseek(fd,0,SEEK_SET);
	read(fd,length,sizeof(*length));
	buf = (char*)malloc(*length);
	read(fd,buf,*length);
	close(fd);
	return buf;
}
int main(int argc, char *argv[])
{
	char* content = "H中国";
	size_t len = strlen(content);
    printf("len content=%d\n",len);
	temp_file_handle fd = write_temp_file(content,len);
	printf("write complete!\n");
	char* ret = read_temp_file(fd, &len);
	printf("%s\n",ret);
	free(ret);
	ret=NULL;
    return 0;
}
