#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    int return_value;
	return_value = system("ls -l / ; echo 'done'");
	printf("return value:%d\n",return_value);
	return return_value;
}
