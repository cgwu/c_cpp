#include <sys/epoll.h>  
#include <netinet/in.h>  
#include <sys/types.h>          /* See NOTES */  
#include <sys/socket.h>  
#include <strings.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <arpa/inet.h>  

typedef struct sockaddr_in sockaddr_in ;  
typedef struct sockaddr     sockaddr ;  
  
#define SER_PORT    8080  
#define IP_ADDR     "127.0.0.1"
  
int main(int argc,char**argv){  
	sockaddr_in srv, cli ;  
	int listen_fd ,con_fd ;  
	socklen_t  len;  
	int res,ws ;  
	char buf[255];  
  
	bzero(&srv,sizeof(srv));  
	bzero(&cli,sizeof(cli));  
	srv.sin_port= SER_PORT ;  
	srv.sin_family = AF_INET ;  
	inet_pton(AF_INET,IP_ADDR,&srv.sin_addr);  
  
	listen_fd = socket(AF_INET,SOCK_STREAM,0);  
	if(connect(listen_fd,(sockaddr*)&srv,sizeof(sockaddr))<0){  
		perror("connect");  
		exit(0);  
	}  
	while(1){  
		res = read(STDIN_FILENO,buf,sizeof(buf)-1);  
		ws = write(listen_fd,buf,res);  
		res = read(listen_fd,buf,sizeof(buf)-1);  
		ws = write(STDOUT_FILENO,buf,res);  
	}  
  
	close(listen_fd);  
	  
	return 0;  
}  
