#include "AVLTree.h"
#include "LinkStack.h"

void initAVLTree(AVLTree *avt) {
    avt->root = NULL;
}

AVLNode* createNode(DataType data) {
    AVLNode *node = (AVLNode*)malloc(sizeof(AVLNode));
    assert(node != NULL);
    node->bf = 0;
    node->data = data;
    node->leftChild = node->rightChild = NULL;
    return node;
}

void RotateL(AVLNode **ptr) {
    AVLNode *subL = *ptr;
    (*ptr) = subL->rightChild;
    subL->rightChild = (*ptr)->leftChild;
    (*ptr)->leftChild = subL;
    (*ptr)->bf = subL->bf = 0;
}
void RotateR(AVLNode **ptr) {
    AVLNode *subR = *ptr;
    (*ptr) = subR->leftChild;
    subR->leftChild = (*ptr)->rightChild;
    (*ptr)->rightChild = subR;
    (*ptr)->bf = subR->bf = 0;
}
void RotateLR(AVLNode **ptr) {
    AVLNode *subR = *ptr;
    AVLNode *subL = subR->leftChild;
    *ptr = subL->rightChild;

    subL->rightChild = (*ptr)->leftChild;
    (*ptr)->leftChild = subL;
    if((*ptr)->bf <= 0) {
        subL->bf = 0;
    } else {
        subL->bf = -1;
    }
    subR->leftChild = (*ptr)->rightChild;
    (*ptr)->rightChild = subR;
    if((*ptr)->bf == -1) {
        subR->bf = 1;
    } else {
        subR->bf = 0;
    }

    (*ptr)->bf = 0;
}
void RotateRL(AVLNode **ptr) {
    AVLNode *subL = *ptr;
    AVLNode *subR = subL->rightChild;
    (*ptr) = subR->leftChild;

    subR->leftChild = (*ptr)->rightChild;
    (*ptr)->rightChild = subR;
    if((*ptr)->bf >= 0) {
        subR->bf = 0;
    } else {
        subR->bf = 1;
    }
    subL->rightChild = (*ptr)->leftChild;
    (*ptr)->leftChild = subL;
    if((*ptr)->bf == 1) {
        subL->bf = -1;
    } else {
        subL->bf = 0;
    }
    (*ptr)->bf = 0;
}

bool _insertAVLTree(AVLNode **start, DataType data) {
    AVLNode *p = *start;
    AVLNode *parent = NULL;

    LinkStack stack;
    InitStack(&stack);

    while(p!=NULL) {
        if(data == p->data) return false;
        parent = p;
        Push(&stack, parent);
        if(data < p->data) p = p->leftChild;
        else p = p->rightChild;
    }
    p = createNode(data);
    if(parent == NULL) {
        *start = p;
        return true;
    }
    if(data < parent->data) {
        parent->leftChild = p;
    } else {
        parent->rightChild = p;
    }

    while(!IsEmpty(&stack)) {
        Pop(&stack, &parent);
        if(parent->leftChild == p) {
            parent->bf--;
        } else {
            parent->bf++;
        }
        if(parent->bf == 0) {
            break;
        } else if(parent->bf==1 || parent->bf==-1) {
            p = parent;
        } else {
            int flag = (parent->bf<0)?-1:1;
            if(p->bf == flag) {
                if(flag == -1) {
                    RotateR(&parent);
                } else {
                    RotateL(&parent);
                }
            } else {
                if(flag == -1) {
                    RotateLR(&parent);
                } else {
                    RotateRL(&parent);
                }
            }
            break;
        }
    }

    if(IsEmpty(&stack)) {
        (*start) = parent;
    } else {
        AVLNode *tmp;
        Pop(&stack, &tmp);
        if(tmp->data > parent->data) {
            tmp->leftChild = parent;
        } else {
            tmp->rightChild = parent;
        }
    }

    return true;
}

bool insertAVL(AVLTree *avt, DataType data) {
    return _insertAVLTree(&avt->root, data);
}
