#include <stdlib.h>
#include <stdio.h>

int main()
{
    union {
        short s;
        char ch[sizeof(short)];
    } un;
    un.s = 0x0102;
    if(sizeof(short)==2){
        if(un.ch[0] == 1 && un.ch[1] == 2){
            printf("big endian\n");
        }
        else if(un.ch[0] == 2 && un.ch[1] == 1){
            printf("little endian\n");
        }
        else printf("unknown\n");
    }
    else{
        printf("sizeof short:%d\n", sizeof(short));
    }

/*
    int short_s = sizeof(short);
    printf("%d\n",short_s);
*/

    return 0;
}

