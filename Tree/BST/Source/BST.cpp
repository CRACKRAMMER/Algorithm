#include "BST.h"

void InitBSTree(BST *bst) {
    bst->root = NULL;
}

bool _insertBSTree(BSTNode **node, ElemType data) {
    if(*node==NULL) {
        *node = (BSTNode*)malloc(sizeof(BSTNode));
        assert((*node)!=NULL);
        (*node)->data = data;
        (*node)->leftChild = NULL;
        (*node)->rightChild = NULL;
        return true;
    } else if(data<(*node)->data) {
        return _insertBSTree(&(*node)->leftChild, data);
    } else if(data>(*node)->data) {
        return _insertBSTree(&(*node)->rightChild, data);
    }
    return false;

}

bool insertBSTree(BST *bst, ElemType data) {
    return _insertBSTree(&(bst->root), data);
}

ElemType _Min(BSTNode *node)  {
   while(node->leftChild) {
       node = node->leftChild;
   }
   return node->data;
}

ElemType Min(BST *bst) {
    return _Min(bst->root);
}

ElemType _Max(BSTNode *node)  {
   while(node->rightChild) {
       node = node->rightChild;
   }
   return node->data;
}

ElemType Max(BST *bst) {
    return _Max(bst->root);
}

void _Sort(BSTNode *node) {
    if(node) {
        _Sort(node->leftChild);
        printf("%d ", node->data);
        _Sort(node->rightChild);
    }
}

void Sort(BST *bst) {
    _Sort(bst->root);
    printf("\n");
}

BSTNode* _Search(BSTNode *node, ElemType key) {
    if(node) {
        if(node->data>key) {
            return _Search(node->leftChild, key);
        } else if(node->data < key) {
            return _Search(node->rightChild, key);
        } else {
            return node;
        }
    }
    return NULL;
}

BSTNode* Search(BST *bst, ElemType key) {
    return _Search(bst->root, key);
}

void _MakeEmptyBSTree(BSTNode **node) {
    if(*node) {
       _MakeEmptyBSTree(&(*node)->leftChild); 
       _MakeEmptyBSTree(&(*node)->rightChild); 
       free(*node);
        *node = NULL;
    }
}
void MakeEmptyBSTree(BST *bst) {
    _MakeEmptyBSTree(&bst->root);
}

bool _RemoveBSTree(BSTNode **node, ElemType key) {
    if(!(*node)) {
        return false;
    } else if((*node)->data > key) {
        return _RemoveBSTree(&(*node)->leftChild, key);
    } else if((*node)->data < key) {
        return _RemoveBSTree(&(*node)->rightChild, key);
    } else {
        if((*node)->rightChild && (*node)->leftChild) {
            ElemType min = _Min((*node)->rightChild);
            (*node)->data = min;
            _RemoveBSTree(&(*node)->rightChild, min);
        } else {
            BSTNode *temp = *node;
            if((*node)->leftChild) {
                *node = (*node)->leftChild;
            } else {
                *node = (*node)->rightChild;
            }
            free(temp);
            temp = NULL;
        }
    }
    return true;
}

bool RemoveBSTree(BST *bst, ElemType key) {
    return _RemoveBSTree(&bst->root, key);
}
