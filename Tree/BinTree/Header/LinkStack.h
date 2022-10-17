#ifndef __LINKSTACK_H__
#define __LINKSTACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct BinTreeNode;

enum STypeTag {L,R};
typedef struct SType {
    BinTreeNode* value;
    STypeTag tag;
}SType;

#define STACK_INIT_SIZE 8
#define STACK_INC_SIZE 8

typedef struct StackNode {
    SType data;
    struct StackNode *next;
}StackNode;

typedef StackNode* LinkStack;

void InitStack(LinkStack *st);
int PushStack(LinkStack *st, SType data);
int PopStack(LinkStack *st, SType *data);
int LengthStack(LinkStack *st);
void ClearStack(LinkStack *st);
void DestroyStack(LinkStack *st);

#endif // __LINKSTACK_H__
