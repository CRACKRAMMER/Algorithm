#include "CSTree.h"

CSTreeNode* _CreateCSTree(char **str, char ch);
CSTreeNode* _FindCSTree(CSTreeNode *node, Elemtype key);
CSTreeNode* _ParentCSTree(CSTreeNode *node);

void InitCSTree(CSTree *tree, Elemtype ch) {
    tree->root = NULL;
    tree->refvalue = ch;
}

CSTreeNode* _CreateCSTree(const char **str, char ch) {
    if(**str == ch)
        return NULL;
    CSTreeNode *node = (CSTreeNode*)malloc(sizeof(CSTreeNode));
    assert(node!=NULL);
    node->data = **str;
    node->fristChild = _CreateCSTree(&(++(*str)), ch);
    node->nextSibling = _CreateCSTree(&(++(*str)), ch);
    return node;
}

void CreateCSTree(CSTree *tree, const char *str) {
    tree->root = _CreateCSTree(&str, tree->refvalue);
}

CSTreeNode* RootCSTree(CSTree *tree) {
    return tree->root;
}

CSTreeNode* FirstChildCSTree(CSTreeNode *node) {
    return node->fristChild;
}

CSTreeNode* NextSiblingCSTree(CSTreeNode *node) {
    return node->nextSibling;
}

CSTreeNode* _FindCSTree(CSTreeNode *node, Elemtype key) {
    if(!node)
        return NULL;
    if(node->data == key)
        return node;
    CSTreeNode *p;
    p = _FindCSTree(node->fristChild, key);
    if(p)
        return p;
    return _FindCSTree(node->nextSibling, key);
}

CSTreeNode* FindCSTree(CSTree *tree, Elemtype key) {
    return _FindCSTree(tree->root, key);
}

CSTreeNode* _ParentCSTree(CSTreeNode *node, CSTreeNode *key) {
    if(node==NULL || key == NULL || key == node)
        return NULL;
    
    CSTreeNode *p = node->fristChild;
    CSTreeNode *parent;
    while(p) {
        if(p==key)
            return node;
        parent = _ParentCSTree(p, key);
        if(parent)
            return parent;
        p = p->nextSibling;
    }
    return NULL;
}

CSTreeNode* ParentCSTree(CSTree *tree, CSTreeNode *key) {
    return _ParentCSTree(tree->root, key);
}
