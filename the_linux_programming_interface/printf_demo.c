#include <stdio.h>
int main(){
    char *s = "this is test example";
    printf("%.*s\n",10,s);      // .后面的*号代表输出字符串的长度
    printf("%*.*s\n",20,10,s);  // .前面的*号代表输出总长度，前面用空格

    return 0;
}
