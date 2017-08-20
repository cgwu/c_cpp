/*
 * 从标准输入读取9个字符
 * 编译命令: gcc cp_in_out.c -I../code/include ../code/src/csapp.o -lpthread
 * */
#include "csapp.h"
int main(int argc, const char *argv[])
{
    int n;
    rio_t rio;
    char buf[MAXLINE];
    Rio_readinitb(&rio, STDIN_FILENO);
    while((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0)
        Rio_writen(STDOUT_FILENO, buf, n);
    exit(0);
    return 0;
}
