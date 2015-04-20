#include <stdio.h>
//#define IVAL 2
//gcc -DIVAL macro.c
//gcc -DIVAL=123 -save-temps macro.c
int main(int argc, char *argv[])
{
    int i = IVAL;
	printf("i=%d\n",i);

    #ifndef IVAL
	printf("IVAL is not defined.!!!!\n");
	#else
	printf("IVAL is defined.!!!!!!!!!\n");
	#endif
	
    return 0;
}
