/*
 * 从标准输入读取9个字符
 * 编译命令: gcc test_rioreadn.c -I../code/include ../code/src/csapp.o -lpthread
 * */
#include "csapp.h"
int main(int argc, const char *argv[])
{
    char buf[10];
    int nread = rio_readn(STDIN_FILENO, buf, 9);
    printf("buf = %s\n",buf);
    exit(0);
    return 0;
}
