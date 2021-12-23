#ifndef __SEQQUEUE_H__
#define __SEQQUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXSIZE 8
#define INCSIZE 5

typedef int ElemType;

typedef struct Queue {
    ElemType *base;
    int front;
    int rear;
    int capacity;
}Queue;

void InitQueue(Queue *Q);
int EnQueue(Queue *Q, ElemType data);
int DeQueue(Queue *Q, ElemType *data);
void ShowQueue(Queue *Q);
int Length(Queue *Q);
void ClearQueue(Queue *Q);
void DestroyQueue(Queue *Q);

#endif // __SEQQUEUE_H__