#include "ThreadBinTree.h"

BinTreeNode* _BuyThreadBinTreeNode(const ElemType data);
BinTreeNode* _CreateThreadBinTree(const char **str, const char flag);
void _CreateInThread(BinTreeNode *node, BinTreeNode **pre);
void _ThreadBinTreeInOrder(BinTreeNode *node);

void InitThreadBinTree(BinTree *tree, const char value) {
  tree->root = NULL;
  tree->refvalue = value;
}

BinTreeNode* _BuyThreadBinTreeNode(const ElemType data) {
    BinTreeNode *node = (BinTreeNode*)malloc(sizeof(BinTreeNode));
    assert(node!=NULL);
    node->data = data;
    node->leftChild = node->rightChild = NULL;
    node->ltag = node->rtag = LINK;
    return node;
}

BinTreeNode* _CreateThreadBinTree(const char **str, const char flag) {
    if(**str == flag) 
        return NULL;
    BinTreeNode *node = _BuyThreadBinTreeNode(**str);
    node->leftChild = _CreateThreadBinTree(&(++(*str)), flag);
    node->rightChild = _CreateThreadBinTree(&(++(*str)), flag);
    return node;
}

void _CreateInThread(BinTreeNode *node, BinTreeNode **pre) {
    if(!node)
        return;
    _CreateInThread(node->leftChild, pre);
    if(node->leftChild==NULL) {
        node->ltag = THREAD;
        node->leftChild = *pre;
    }
    if(*pre && (*pre)->rightChild==NULL) {
        (*pre)->rtag = THREAD;
        (*pre)->rightChild = node;
    }
    *pre = node;
    _CreateInThread(node->rightChild, pre);
}

void CreateThreadBinTree(BinTree *tree, const char **str) {
    tree->root = _CreateThreadBinTree(str, tree->refvalue);
    BinTreeNode *pre = NULL;
    _CreateInThread(tree->root, &pre);
    pre->rtag = THREAD;
    pre->rightChild = NULL;
}

BinTreeNode* ThreadBinTreeFirst(BinTreeNode *node) {
    if(!node)
        return NULL;
    while(node->ltag == LINK) {
        node = node->leftChild;
    }
    return node;
}

BinTreeNode* ThreadBinTreeLast(BinTreeNode *node) {
    if(!node)
        return NULL;
    while(node->rtag == LINK) {
        node = node->rightChild;
    }
    return node;
}

BinTreeNode* ThreadBinTreeNext(BinTreeNode *node) {
    if(node == NULL)
        return NULL;
    if(node->rtag == THREAD)
        return node->rightChild;
    return ThreadBinTreeFirst(node->rightChild);
    
}

BinTreeNode* ThreadBinTreePrio(BinTreeNode *node) {
    if(node == NULL)
        return NULL;
    if(node->ltag == THREAD)
        return node->leftChild;
    return ThreadBinTreeLast(node->leftChild);
}


void ThreadBinTreeInOrder(BinTree *tree) {
    BinTreeNode *node = tree->root;
    for(node=ThreadBinTreeFirst(node); node!=NULL; node=ThreadBinTreeNext(node)) {
        printf("%c ", node->data);
    }
    printf("\n");
}

BinTreeNode* ThreadBinTreeSearch(BinTree *tree, ElemType data) {
    BinTreeNode *node = tree->root;
    if(!node)
        return NULL;
    for(node=ThreadBinTreeFirst(node); node!=NULL; node=ThreadBinTreeNext(node)) {
        if(node->data==data)
            return node;
    }
    return NULL;
}

BinTreeNode* ThreadBinTreeParent(BinTreeNode *cur) {
    if(!cur)
        return NULL;

    BinTreeNode *node;

    if(cur->ltag==THREAD) {
        node = cur->leftChild;
        if(node->rightChild == cur)
            return node;
    }
    if(cur->rtag==THREAD) {
        node = cur->rightChild;
        if(node->leftChild == cur)
            return node;
    }

    node = ThreadBinTreeFirst(cur->leftChild);
    node = node->leftChild;
    if(node && node->rightChild == cur)
        return node;

    node = ThreadBinTreeLast(cur->rightChild);
    if(node->rightChild)
        return node->rightChild;
    return NULL;
}
