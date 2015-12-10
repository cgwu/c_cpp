#include <stdio.h>
#include <windows.h>
char buf[1024];
int main(){
	//printf("default BUFSIZE:%d\n", BUFSIZE);
	//setvbuf(stdout,NULL, _IONBF, 0);	//不缓存
	setvbuf(stdout, buf, _IOLBF, 1024); //行缓存
	printf("Hello");
	Sleep(3000);
	printf("wor\n");
	//Sleep(2000);
	//printf("after");
	//Sleep(3000);
	return 0;
}