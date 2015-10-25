#include <stdio.h>
//#include <stdlib.h>
#include <stdarg.h>

double sum(void * foo, ...){
	double s = 0;
	va_list argptr;
	va_start(argptr, foo);
	s += va_arg(argptr,int);
	s += va_arg(argptr,double);
	s += va_arg(argptr,long long);
	va_end( argptr );
	return s;
}

/* run this program using the console pauser or 
add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	//printf("HelloÖÐ¹úÍòËê\n");
	//system("pause");
	int i = 1;
	double d = 3.14;
	long long lng = 200;
	double s = sum(NULL,i,d,lng);
	printf("%f\n",s);
	printf("sizeof(long)=%d\n", sizeof(long));
	printf("sizeof(long long)=%d", sizeof(long long));
	return 0;
}
