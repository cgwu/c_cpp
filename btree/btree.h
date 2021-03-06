#ifndef BTREE_H
#define BTREE_H

typedef char ElemType;
typedef struct __BTN{
    ElemType elem;
    struct __BTN *left, *right;
} BTreeNode;

// 1. 初始二叉树，即把它置为一棵空树
extern void InitBTree(BTreeNode **root);

// 2. 根据广义表表示的二叉树建立对应的存储结构
extern void CreateBTree(BTreeNode **root, char *s);

// 3. 判断一棵二叉树是否为空，若是返回1，否则返回0
extern int IsBTreeEmpty(BTreeNode *root);

// 4. 按照一定次序遍历一棵二叉树，每个结点均要访问一次
//extern void TraverseBTree(BTreeNode *root);

// 5. 从二叉树查找值为x的结点，若存在返回结点存储位置，否则返回NULL
extern BTreeNode * FindBTree(BTreeNode *root, ElemType x);

// 6. 求出一棵二叉树的深度并返回
extern int BTreeDepth(BTreeNode *root);

// 7. 按照树的一种表示方法输出一棵二叉树,广义表
extern void PrintBTree(BTreeNode *root);

// 8. 清除二叉树中的所有结点，使之变成一棵空树
extern void ClearBTree(BTreeNode **root);

//前序遍历
extern void PreOrder(BTreeNode *root);

//中序遍历
extern void InOrder(BTreeNode *root);

//后序遍历
extern void LastOrder(BTreeNode *root);

//按层遍历
extern void LevelOrder(BTreeNode *root);
#endif

