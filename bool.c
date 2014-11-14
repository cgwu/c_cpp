#include <stdio.h>
#include <stdbool.h>

int main(){
	bool b = true;
	printf("%d\n",b);
	if(b) printf("b 为真\n");

	bool bf = false;
	printf("%d\n",bf);
	if(!bf) printf("bf为假bf为假bf为假bf为假bf为假\n");
    printf("sizeof bool:%d\n",sizeof(bool));

	return 0;
}
