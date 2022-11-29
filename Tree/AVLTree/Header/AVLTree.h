#ifndef __AVLTREE_H__
#define __AVLTREE_H__
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define DataType int 

typedef struct AVLNode {
    DataType data;
    AVLNode *leftChild;
    AVLNode *rightChild;
    int bf;
}AVLNode;

typedef struct AVLTree {
    AVLNode *root;
}AVLTree;

void initAVLTree(AVLTree *avt);
AVLNode* createNode(DataType data);
bool _insertAVL(AVLNode **node, DataType data);
bool insertAVL(AVLTree *avt, DataType data);
void RotateL(AVLNode **ptr);
void RotateR(AVLNode **ptr);
void RotateLR(AVLNode **ptr);
void RotateRL(AVLNode **ptr);

#endif //__AVLTREE_H__
