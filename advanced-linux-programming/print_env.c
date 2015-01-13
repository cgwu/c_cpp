#include <stdio.h>
#include <stdlib.h>
extern char** environ;

int main(int argc, char *argv[])
{
    char** var;
	for(var = environ; *var!=NULL; ++var){
		printf("%s\n",*var);
	}
	printf("-----------------------\n");
	char* home = getenv("HOME");
	printf("home=%s\n",home);
	printf("-----------------------\n");
	printf("sizeof(char**):%d\n",sizeof(char**));
	printf("sizeof(NULL):%d;NULL=%d\n",sizeof(NULL),NULL);
	
    return 0;
}
