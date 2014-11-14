#include <stdio.h>
#include "btree.h"
int main(){
    //char str[] ="a(b(c),d(e(f,g),h(,i)))";
    char str[] = "d(e(f,g),h(,i))";
    //char str[] = "a(b,c)";
    BTreeNode * root;
    InitBTree(&root);
    CreateBTree(&root, str);
    printf("前序遍历:\n");
    PreOrder(root);
    printf("\n中序遍历:\n");
    InOrder(root);
    printf("\n");

    ClearBTree(&root);

    printf("done\n");
    return 0;
}

