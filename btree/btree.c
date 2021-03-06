#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

#define MaxStackSize 20

// 1. 初始二叉树，即把它置为一棵空树
void InitBTree(BTreeNode **root){
    *root = NULL;
}

// 2. 根据广义表表示的二叉树建立对应的存储结构
// a(b(c),d(e(f,g),h(,i)))
void CreateBTree(BTreeNode **root, char *s){
    BTreeNode ** stack[MaxStackSize] = {0,};
    int top = -1;
    BTreeNode * pnode = NULL;
    BTreeNode ** pcurrent = root;
    for(; *s; s++){
        //printf("处理:%c\n",*s);
        switch(*s){
            case ' ':
                break;
            case '(':
                stack[++top] = pcurrent;
                pcurrent = & (*pcurrent)->left;
                break;
            case ')':
                top--;
                break;
            case ',':
                if(top < 0) printf("stack index error.\n");
                pcurrent = & (*stack[top])->right;
                break;
            default:
                pnode = malloc(sizeof(BTreeNode));
                pnode->left = NULL;
                pnode->right = NULL;
                pnode->elem = *s;
                *pcurrent = pnode;
        }
    }   
    printf("CreateBTree done.\n");
}

// 3. 判断一棵二叉树是否为空，若是返回1，否则返回0
int IsBTreeEmpty(BTreeNode *root){
    return root == NULL ? 0 : 1;
}

// 4. 按照一定次序遍历一棵二叉树，每个结点均要访问一次
//void TraverseBTree(BTreeNode *root);

// 5. 从二叉树查找值为x的结点，若存在返回结点存储位置，否则返回NULL
BTreeNode * FindBTree(BTreeNode *root, ElemType x){
    if(root != NULL){
        if(root->elem == x) return root;
        BTreeNode * lr = FindBTree(root->left, x);
        if(lr != NULL) return lr;
        lr = FindBTree(root->right, x);
        if(lr != NULL) return lr;
    }
    return NULL;
}

// 6. 求出一棵二叉树的深度并返回
int BTreeDepth(BTreeNode *root){
    if(root == NULL) return 0;
    int left = BTreeDepth(root->left);
    int right = BTreeDepth(root->right);
    return (left > right ? left: right ) + 1;
}

// 7. 按照树的一种表示方法输出一棵二叉树,广义表
void PrintBTree(BTreeNode *root){
   if(root != NULL){
        printf("%c",root->elem);
        if(root->left != NULL || root->right != NULL){
            printf("(");
            PrintBTree(root->left);
            if(root->right) printf(",");
            PrintBTree(root->right);
            printf(")");
        }
   }
}

// 8. 清除二叉树中的所有结点，使之变成一棵空树
void ClearBTree(BTreeNode **root){
    if( *root != NULL){
        ClearBTree(&(*root)->left);
        ClearBTree(&(*root)->right);
        free(*root);
        *root = NULL;
    }
}

void PreOrder(BTreeNode *root){
    if(root != NULL){
        printf("%c ",root->elem);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void InOrder(BTreeNode *root){
    if(root != NULL){
        InOrder(root->left);
        printf("%c ",root->elem);
        InOrder(root->right);
    }
}

void LastOrder(BTreeNode *root){
    if(root != NULL){
        LastOrder(root->left);
        LastOrder(root->right);
        printf("%c ",root->elem);
    }
}

//按层遍历
typedef struct __BTreeNodeLink{
    BTreeNode *node;
    struct __BTreeNodeLink *next;
} BTreeNodeLink;

void LevelOrder(BTreeNode *root){
    if(root == NULL) return;
    BTreeNodeLink *phead = malloc(sizeof(BTreeNodeLink)); //队列头指针
    phead->node = root;
    phead->next = NULL;
    BTreeNodeLink *ptail = phead;   //队列尾指针
    while(phead != NULL){
        BTreeNode *pnode = phead->node;
        printf("%c ",pnode->elem);
        if(pnode->left){
            BTreeNodeLink *ptmp = malloc(sizeof(BTreeNodeLink));
            ptmp->node = pnode->left;
            ptmp->next = NULL;
            ptail->next = ptmp;
            ptail = ptmp;
        }
        if(pnode->right){
            BTreeNodeLink *ptmp = malloc(sizeof(BTreeNodeLink));
            ptmp->node = pnode->right;
            ptmp->next = NULL;
            ptail->next = ptmp;
            ptail = ptmp;
        }
        BTreeNodeLink *ptmp = phead;
        phead = phead->next;
        free(ptmp);
    } 
}

