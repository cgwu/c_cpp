#include <stdio.h>
int main(int argc, char *argv[])
{
    printf("程序名:%s\n",argv[0]);
	printf("参数个数:%d\n",argc-1);
	if(argc>1){
		for(int i=1;i<argc;i++){
			printf("参数%d为:%s\n",i,argv[i]);
		}
	}
    return 0;
}
