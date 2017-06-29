#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
int main(int argc, char *argv[]){
    printf("Running ps with system.\n");
    system("ps ax &");
    printf("Done.\n");
    exit(0);
//    return 0;
}
