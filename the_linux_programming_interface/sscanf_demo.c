#include <stdio.h>
#include <sys/select.h>
#include <sys/epoll.h>

int main(int argc, char *argv[]){
    int fd,i,numRead;
    char buf[10];
    printf("argc=%d\n", argc);
    if(argc < 2){
        fprintf(stderr, "argc error\n");
        return 1;
    }
    for(i=1; i<argc; i++){
        numRead = sscanf(argv[i], "%d%2[rw]", &fd, buf); // %2[rw] : 最多只读取2个字符,包含字符为r,w.
        printf("numRead=%d, rd=%d, buf=%s\n", numRead, fd, buf);
    }

    printf("FD_SETSIZE=%d\n", FD_SETSIZE);
    printf("sizeof(fd_set) = %d\n", sizeof(fd_set));
    printf("sizeof(epoll_event) = %d\n", sizeof(struct epoll_event));
    return 0;
}
