#include <stdio.h>
int main(int argc, char *argv[])
{
    int c = f();
	printf("c=%d\n",c);
    return 0;
}
/*
shell command:

static library compile:
gcc -c test.c
ar cr libtest.a test.o
gcc -o app.out app.c -L. -ltest

shared (dynamic linking) library compile:
gcc -c test.c
gcc -shared -fPIC libtest.so test.o
gcc -o app_shared.out -L. -ltest
导出动态库环境变量:
LD_LIBRARY_PATH=./
export LD_LIBRARY_PATH
*/
