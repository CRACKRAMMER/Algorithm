#include "BinTree.h"
#include "LinkQueue.h"
#include "LinkStack.h"

BinTreeNode* _CreateBinTree(BinTree *tree, const char **str);
void _PreOrder(BinTreeNode *node);
void _InOrder(BinTreeNode *node);
void _PostOrder(BinTreeNode *node);
void _LevelOrder(LinkQueue *queue);
void _LevelOrderIteration(BinTreeNode *node);
int _SizeBinTree(BinTreeNode *node);
int _HeightBinTree(BinTreeNode *node);
BinTreeNode* _SearchBinTree(BinTreeNode *node, ElemType key);
BinTreeNode* _ParentBinTree(BinTreeNode *node, BinTreeNode *key);
void _CopyBinTree(BinTreeNode **dest, BinTreeNode *src);
void _ClearBinTree(BinTreeNode **node);
BinTreeNode* _CreateBinTreeByPre(BinTreeNode *node, const char *pre, const char *middle, int n);
BinTreeNode* _CreateBinTreeByPost(const char *post, const char *middle, int n);

void InitBinTree(BinTree *tree, char ch) {
    tree->root = NULL;
    tree->refvalue = ch;
}

BinTreeNode* _CreateBinTreeByStr(const char **str, char tag) {
    if(**str==tag) {
        return NULL;
    } else {
        BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
        assert(t!=NULL);
        t->data = **str;
        t->left = _CreateBinTreeByStr(&(++(*str)), tag);
        t->right = _CreateBinTreeByStr(&(++(*str)), tag);
        return t;
    }
}
void CreateBinTreeByStr(BinTree *tree, const char **str) {
    tree->root = _CreateBinTreeByStr(str, tree->refvalue);
}

void PreOrder(BinTree *tree) {
    _PreOrder(tree->root);
    printf("\n");
}
void _PreOrder(BinTreeNode *node) {
    if(node) {
        printf("%c ", node->data);
        _PreOrder(node->left);
        _PreOrder(node->right);
    }
}

void InOrder(BinTree *tree) {
    _InOrder(tree->root);
    printf("\n");
}
void _InOrder(BinTreeNode *node) {
    if(node) {
        _PreOrder(node->left);
        printf("%c ", node->data);
        _PreOrder(node->right);
    }
}

void PostOrder(BinTree *tree) {
    _PostOrder(tree->root);
    printf("\n");
}
void _PostOrder(BinTreeNode *node) {
    if(node) {
        _PreOrder(node->left);
        _PreOrder(node->right);
        printf("%c ", node->data);
    }
}

void _LevelOrder(LinkQueue *queue) {
    if(!LengthQueue(queue))
        return;
    BinTreeNode *node;
    DeQueue(queue, &node);

    printf("%c ", node->data);
    if(node->left)
        EnQueue(queue, node->left);
    if(node->right)
        EnQueue(queue, node->right);
    _LevelOrder(queue);
}

void LevelOrder(BinTree *tree) {
    LinkQueue queue;
    InitQueue(&queue);
    if(tree->root) {
        EnQueue(&queue, tree->root);
        _LevelOrder(&queue);
        printf("\n");
    }
}

void _LevelOrderIteration(BinTreeNode *node) {
    LinkQueue queue;
    InitQueue(&queue);
    EnQueue(&queue, node);

    while(LengthQueue(&queue)) {
        DeQueue(&queue, &node);
        printf("%c ", node->data);
        if(node->left)
            EnQueue(&queue,node->left);
        if(node->right)
            EnQueue(&queue,node->right);
    }
}

void LevelOrderIteration(BinTree *tree) {
    _LevelOrderIteration(tree->root);
    printf("\n");
}

int _SizeBinTree(BinTreeNode *node) {
   if(!node)
       return 0;
   return _SizeBinTree(node->left) + _SizeBinTree(node->right) + 1;
}
int SizeBinTree(BinTree *tree) {
    return _SizeBinTree(tree->root);
}

int _HeightBinTree(BinTreeNode *node) {
    if(!node)
        return 0;
    int left, right;
    left = _HeightBinTree(node->left);
    right = _HeightBinTree(node->right);
    return (left>right?left:right) + 1;
}
int HeightBinTree(BinTree *tree) {
    return _HeightBinTree(tree->root);
}

BinTreeNode* _SearchBinTree(BinTreeNode *node, ElemType key) {
    if(!node) {
        return NULL;
    }
    if(node->data == key) {
        return node;
    }
    BinTreeNode *left, *right;
    left = _SearchBinTree(node->left, key);
    if(left) {
        return left;
    }
    right = _SearchBinTree(node->right, key);
    return right;
}

BinTreeNode* SearchBinTree(BinTree *tree, ElemType key) {
    return _SearchBinTree(tree->root, key);
}

BinTreeNode* _ParentBinTree(BinTreeNode *node, BinTreeNode *key) {
    if(node==NULL || node==key)
        return NULL;
    if(node->left && node->left == key)
        return node;
    else if(node->right && node->right == key)
        return node;
    BinTreeNode *left, *right;
    left = _ParentBinTree(node->left, key);
    if(left) {
        return left;
    }
    right = _ParentBinTree(node->right, key);
    return right;
}

BinTreeNode* ParentBinTree(BinTree *tree, BinTreeNode *key) {
    return _ParentBinTree(tree->root, key);
}

BinTreeNode* LeftBinTree(BinTreeNode *node) {
    return node->left;
}

BinTreeNode* RightBinTree(BinTreeNode *node) {
    return node->right;
}

bool BinTreeEmpty(BinTree *tree) {
    return tree->root == NULL;
}
void _CopyBinTree(BinTreeNode **dest, BinTreeNode *src) {
    if(!src)
        return;
    (*dest) = (BinTreeNode*)malloc(sizeof(BinTreeNode));
    assert(*dest!=NULL);
    (*dest)->data = src->data;
    (*dest)->left = (*dest)->right = NULL;
    _CopyBinTree(&(*dest)->left, src->left);
    _CopyBinTree(&(*dest)->right, src->right);
}
void CopyBinTree(BinTree *dest, BinTree *src) {
    dest->refvalue = src->refvalue;
    _CopyBinTree(&dest->root, src->root);
}
void _ClearBinTree(BinTreeNode **node) {
    if(!(*node))
        return;
    _ClearBinTree(&(*node)->left);
    _ClearBinTree(&(*node)->right);
    free(*node);
    (*node) = NULL;
}

void ClearBinTree(BinTree *tree) {
    _ClearBinTree(&tree->root);
}

void PreOrderIteration(BinTree *tree) {
    BinTreeNode *node = tree->root;
    if(!node)
        return;
    LinkStack stack;
    InitStack(&stack);
    SType st;
    st.value = node;
    PushStack(&stack, st);
    while(LengthStack(&stack)) {
        PopStack(&stack, &st);
        node = st.value;
        printf("%c ", node->data);
        if(node->right) {
            st.value = node->right;
            PushStack(&stack, st);
        }
        if(node->left) {
            st.value = node->left;
            PushStack(&stack, st);
        }
    }
    printf("\n");
}

void InOrderIteration(BinTree *tree) {
    BinTreeNode *node = tree->root;
    if(!node)
        return;
    LinkStack stack;
    InitStack(&stack);
    SType st;
    st.value = node;
    PushStack(&stack, st);
    while(LengthStack(&stack)) {
        while(node && node->left) {
            st.value = node->left;
            PushStack(&stack, st);
            node = node->left;
        }
        PopStack(&stack, &st);
        node = st.value;
        printf("%c ", node->data);
        node = node->right;
        if(node) {
            st.value = node;
            PushStack(&stack, st);
        }
    }
    printf("\n");
}

void PostOrderIteration(BinTree *tree) {
    BinTreeNode *node = tree->root;
    if(!node)
        return;
    LinkStack stack;
    InitStack(&stack);
    SType st;
    do {
        while(node) {
            st.value = node;
            st.tag = L;
            PushStack(&stack, st);
            node = node->left;
        }
        bool flag = true;
        while(flag && LengthStack(&stack)) {
            PopStack(&stack, &st);
            switch(st.tag) {
                case L:
                    st.tag = R;
                    PushStack(&stack, st);
                    node = st.value->right;
                    flag = false;
                    break;
                case R:
                    printf("%c ", st.value->data);
                    break;
            }
        }

    } while(LengthStack(&stack));
    printf("\n");
}

BinTreeNode* _CreateBinTreeByPre(const char *pre, const char *middle, int n) {
    if(n<=0)
        return NULL;
    BinTreeNode *node = (BinTreeNode*)malloc(sizeof(BinTreeNode));
    assert(node!=NULL);
    node->data = pre[0];
    int k=0;
    while(k<n && pre[0]!=middle[k])
        k++;
    assert(k!=n);
    node->left = _CreateBinTreeByPre(pre+1, middle, k);
    node->right = _CreateBinTreeByPre(pre+k+1, middle+k+1, n-k-1);
    return node;
}

void CreateBinTreeByPre(BinTree *tree, const char *pre, const char *middle) {
    int prelen = strlen(pre);
    int middlelen = strlen(middle);
    assert(prelen==middlelen);
    tree->root =  _CreateBinTreeByPre(pre, middle, middlelen);
}

BinTreeNode* _CreateBinTreeByPost(const char *post, const char *middle, int n) {
    if(n<=0)
        return NULL;
    BinTreeNode *node = (BinTreeNode*)malloc(sizeof(BinTreeNode));
    assert(node!=NULL);
    node->data = post[n-1];
    int k=0;
    while(k<n && post[n-1]!=middle[k])
        k++;
    assert(k!=n);
    node->left = _CreateBinTreeByPost(post, middle, k);
    node->right = _CreateBinTreeByPost(post+k, middle+k+1, n-k-1);
    return node;
}

void CreateBinTreeByPost(BinTree *tree, const char *post, const char *middle) {
    int postlen = strlen(post);
    int middlelen = strlen(middle);
    assert(postlen==middlelen);
    tree->root = _CreateBinTreeByPost(post, middle, middlelen);
}
