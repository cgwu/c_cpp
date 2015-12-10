#include <stdio.h>
typedef struct Rational {
	int num, den;
} Rational;

void print(Rational r){
	printf("%d / %d\n", r.num, r.den);
}


int main(){
	Rational r = {1, 2};	// cl & gcc 都支持
	printf("%d / %d\n", r.num, r.den);
	print((Rational){3,4});	// cl不支持，gcc支持
	return 0;
}