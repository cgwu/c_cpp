#include <stdio.h>
int main(int argc, char *argv[])
{
    int c = f();
	printf("c=%d\n",c);
    return 0;
}
/*
shell command:
gcc -c test.c
ar cr libtest.a test.o
gcc -o app app.c -L. -ltest
*/
