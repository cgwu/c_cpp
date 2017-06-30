#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *filename;
    if(argc != 2) {
        fprintf(stderr, "useage: useupper file\n");
        exit(1);
    }
    filename = argv[1];
    // 将文件绑定到标准输入
    if(!freopen(filename,"r", stdin)){
        fprintf(stderr, "could not redirect stdin from file %s\n", filename);
        exit(2);
    }
    execl("./upper.o", "upper", 0);
    perror("could not exec ./upper.o");
    exit(3);
    //return 0;
}
