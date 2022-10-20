#ifndef __CSTREE_H__
#define __CSTREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define Elemtype char

typedef struct CSTreeNode {
    Elemtype data;
    CSTreeNode *fristChild;
    CSTreeNode *nextSibling;
}CSTreeNode;

typedef struct CSTree {
    CSTreeNode *root;
    Elemtype refvalue;
}CSTree;

void InitCSTree(CSTree *tree, Elemtype ch);
void CreateCSTree(CSTree *tree, const char *str);
CSTreeNode *RootCSTree(CSTree *tree);
CSTreeNode *FirstChildCSTree(CSTreeNode *node);
CSTreeNode *NextSiblingCSTree(CSTreeNode *node);
CSTreeNode *FindCSTree(CSTree *tree, Elemtype key);
CSTreeNode *ParentCSTree(CSTree *tree, CSTreeNode *node);

#endif //__CSTREE_H__
