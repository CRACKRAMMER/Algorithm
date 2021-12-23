#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int ElemType;

typedef struct QueueNode {
    ElemType data;
    struct QueueNode *next;
}QueueNode;

typedef struct LinkQueue {
    QueueNode *front;
    QueueNode *tail;
}LinkQueue;

void InitQueue(LinkQueue *Q);
int EnQueue(LinkQueue *Q, ElemType data);
int DeQueue(LinkQueue *Q, ElemType *data);
void ShowQueue(LinkQueue *Q);
int Length(LinkQueue *Q);
void ClearQueue(LinkQueue *Q);
void DestroyQueue(LinkQueue *Q);

#endif // __LINKQUEUE_H__