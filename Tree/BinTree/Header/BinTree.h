#ifndef __BINTREE_H__
#define __BINTREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

typedef char ElemType;

typedef struct BinTreeNode {
    ElemType data;
    BinTreeNode *left, *right;
}BinTreeNode;

typedef struct BinTree {
    char refvalue;
    BinTreeNode *root;
} BinTree;

typedef BinTreeNode* EType;

void InitBinTree(BinTree *tree, char ch);
void CreateBinTreeByStr(BinTree *tree, const char **str);
void CreateBinTreeByPre(BinTree *tree, const char *pre, const char *middle);
void CreateBinTreeByPost(BinTree *tree, const char *post, const char *middle);

void PreOrder(BinTree *tree);
void PreOrderIteration(BinTree *tree);
void InOrder(BinTree *tree);
void InOrderIteration(BinTree *tree);
void PostOrder(BinTree *tree);
void PostOrderIteration(BinTree *tree);
void LevelOrder(BinTree *tree);
void LevelOrderIteration(BinTree *tree);

int SizeBinTree(BinTree *tree);
int HeightBinTree(BinTree *tree);
BinTreeNode* SearchBinTree(BinTree *tree, ElemType key);
BinTreeNode* ParentBinTree(BinTree *tree, BinTreeNode *key);
BinTreeNode* LeftBinTree(BinTreeNode *node);
BinTreeNode* RightBinTree(BinTreeNode *node);
void CopyBinTree(BinTree *dest, BinTree *src);
bool BinTreeEmpty(BinTree *tree);
void ClearBinTree(BinTree *tree);

#endif //__BINTREE_H__
