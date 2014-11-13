#include <stdio.h>
int main(){
    int *pa, *pb;
    int a = 1, b = 2;
    pa = &a;
    pb = &b;
    printf("a=%d,b=%d\n",*pa,*pb);

    return 0;
}
