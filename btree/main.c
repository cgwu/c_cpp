#include <stdio.h>
#include "btree.h"
int main(){
    char str[] ="a(b(c),d(e(f,g),h(,i)))";
    //char str[] = "d(e(f,g),h(,i))";
    //char str[] = "a(b,c)";
    BTreeNode * root;
    InitBTree(&root);
    CreateBTree(&root, str);
    printf("前序遍历:\n");
    PreOrder(root);
    printf("\n中序遍历:\n");
    InOrder(root);
    printf("\n后序遍历:\n");
    LastOrder(root);
    printf("\n");
    ElemType elem = 'g';
    printf("查找:%c\n",elem);
    BTreeNode *pr = FindBTree(root,elem);
    if(pr == NULL) printf("元素未找到.\n");
    else printf("元素成功找到:%c\n",pr->elem);
    

    printf("树是否为空(1是;0否):%d\n",IsBTreeEmpty(root));
    ClearBTree(&root);
    printf("树已清除.\n");
    printf("树是否为空(1是;0否):%d\n",IsBTreeEmpty(root));

    printf("done\n");
    return 0;
}

