#ifndef __SEQSTACK_H__
#define __SEQSTACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int ElemType;

#define STACK_INIT_SIZE 8
#define STACK_INC_SIZE 8

typedef struct SeqStack {
    ElemType *base;
    int capacity;
    int top;
}SeqStack;

void InitStack(SeqStack *st);
bool Inc(SeqStack *st);
int Push(SeqStack *st, ElemType data);
int Pop(SeqStack *st, ElemType *data);
bool IsEmpty(SeqStack *st);
bool IsFull(SeqStack *st);
void Show(SeqStack *st);
int Length(SeqStack *st);
void Clear(SeqStack *st);
void Destroy(SeqStack *st);

#endif // __SEQSTACK_H__