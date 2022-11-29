#ifndef __BST_H__
#define __BST_H__
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#define ElemType int

typedef struct BSTNode {
    ElemType data;
    BSTNode *leftChild;
    BSTNode *rightChild;
} BSTNode;

typedef struct BST {
    BSTNode *root;
} BST;

void InitBSTree(BST *bst);
bool _insertBSTree(BSTNode **node, ElemType data);
bool insertBSTree(BST *bst, ElemType data);
ElemType _Min(BSTNode *node);
ElemType Min(BST *bst);
ElemType _Max(BSTNode *node);
ElemType Max(BST *bst);
void _Sort(BSTNode *node);
void Sort(BST *bst);
BSTNode* _Search(BSTNode *node, ElemType key);
BSTNode* Search(BST *bst, ElemType key);
void _MakeEmptyBSTree(BSTNode **node);
void MakeEmptyBSTree(BST *bst);
bool _RemoveBSTree(BSTNode **node, ElemType key);
bool RemoveBSTree(BST *bst, ElemType key);

#endif //__BST_H__
