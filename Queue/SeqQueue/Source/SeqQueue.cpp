#include "SeqQueue.h"

void InitQueue(Queue *Q) {
    Q->base = (ElemType *)malloc(sizeof(ElemType) * MAXSIZE);
    assert(Q->base != NULL);
    Q->front = Q->rear = 0;
    Q->capacity = MAXSIZE;
}

int EnQueue(Queue *Q, ElemType data) {
    if(((Q->rear + 1) % Q->capacity) == Q->front) return -1;
    
    Q->base[Q->rear] = data;
    Q->rear = (Q->rear + 1) % Q->capacity;
    return 0;
}

int DeQueue(Queue *Q, ElemType *data) {
    if(Q->front == Q->rear) return -1;

    if(data != NULL) *data = Q->base[Q->front];
    Q->front = (Q->front + 1) % Q->capacity;
    return 0;
}


void ShowQueue(Queue *Q) {
    printf("front:> ");
    for(int i = Q->front; i != Q->rear;) {
        printf("%d ",Q->base[i]);
        i = (i+1) % Q->capacity;
    }
    printf("<:rear\n");
}

int Length(Queue *Q) {
    return (Q->capacity + (Q->rear - Q->front)) % Q->capacity;
}

void ClearQueue(Queue *Q) {
    Q->front = Q->rear = 0;
}

void DestroyQueue(Queue *Q) {
    ClearQueue(Q);
    free(Q->base);
    Q->base = NULL;
    Q->capacity = 0;
}