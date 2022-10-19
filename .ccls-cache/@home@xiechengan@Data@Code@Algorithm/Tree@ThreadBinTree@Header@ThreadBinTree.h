#ifndef __THREADBINTREE_H__
#define __THREADBINTREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#define ElemType char

typedef enum{LINK, THREAD} TagType;

typedef struct BinTreeNode {
    ElemType data;
    BinTreeNode *leftChild;
    BinTreeNode *rightChild;
    TagType ltag;
    TagType rtag;
}BinTreeNode;

typedef struct BinTree {
    BinTreeNode *root;
    char refvalue;
} BinTree;

#endif //__THREADBINTREE_H__
