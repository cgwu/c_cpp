#include <stdio.h>
int main(int argc, char *argv[])
{
	const int cnt = 5;
	int i=0;
	for (; i < cnt; ++i){
		printf("sleeping: %d\n",i);
		sleep(1);
	}
	printf("----------------------\n");
	for (i = 0; i < cnt; ++i){
		fprintf(stderr,"sleeping: %d\n",i);
		sleep(1);
	}
	
	printf("done.\n");
	return 0;
}
