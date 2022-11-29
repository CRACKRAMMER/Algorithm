#ifndef __LINKSTACK_H__
#define __LINKSTACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct AVLNode;

typedef AVLNode* ElemType;

#define STACK_INIT_SIZE 8
#define STACK_INC_SIZE 8

typedef struct StackNode {
    ElemType data;
    struct StackNode *next;
}StackNode;

typedef StackNode* LinkStack;

void InitStack(LinkStack *st);
LinkStack BuyNode(ElemType data);
int Push(LinkStack *st, ElemType data);
int Pop(LinkStack *st, ElemType *data);
ElemType GetTop(LinkStack *st);
bool IsEmpty(LinkStack *st);
int Length(LinkStack *st);
void Clear(LinkStack *st);
void Destroy(LinkStack *st);

#endif // __LINKSTACK_H__
