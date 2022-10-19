#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct BinTreeNode;

typedef BinTreeNode* QType;

typedef struct QueueNode {
    QType data;
    struct QueueNode *next;
}QueueNode;

typedef struct LinkQueue {
    QueueNode *front;
    QueueNode *tail;
}LinkQueue;

void InitQueue(LinkQueue *Q);
int EnQueue(LinkQueue *Q, QType data);
int DeQueue(LinkQueue *Q, QType *data);
void ShowQueue(LinkQueue *Q);
int LengthQueue(LinkQueue *Q);
void ClearQueue(LinkQueue *Q);
void DestroyQueue(LinkQueue *Q);

#endif // __LINKQUEUE_H__
