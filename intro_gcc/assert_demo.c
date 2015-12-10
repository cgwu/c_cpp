#include <stdio.h>
#include <assert.h>
int main(){
	int a,b;
	float c = 0;
	printf("enter 2 nums:");
	scanf("%d%d", &a ,&b);
	assert(b != 0);
	c = (float)a / b;
	printf("%d / %d = %f\n", a, b, c);
	
	return 0;
}