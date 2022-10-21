#include "LinkQueue.h"

void InitQueue(LinkQueue *Q) {
    Q->front = (QueueNode *)malloc(sizeof(QueueNode));
    assert(Q->front != NULL);
    Q->front->next = NULL;
    Q->tail = Q->front;
}

QueueNode* BuyNode(LinkQueue *Q, QType data) {
    QueueNode *s = (QueueNode *)malloc(sizeof(QueueNode));
    if(s != NULL) {
        s->data = data;
        s->next = NULL;
    }
    return s;
}

int EnQueue(LinkQueue *Q, QType data) {
    QueueNode *s = BuyNode(Q, data);
    if(s == NULL) return -1;
    Q->tail = Q->tail->next = s;
    return 0;
}

int DeQueue(LinkQueue *Q, QType *data) {
    QueueNode *s = Q->front->next;
    if(s == NULL) return -1;
    if(data != NULL) *data = s->data;
    if(Q->tail == s) {
        Q->tail = Q->front;
    }
    Q->front->next = s->next;
    free(s);
    return 0;
}

void ShowQueue(LinkQueue *Q) {
    QueueNode *s = Q->front->next;
    while(s != NULL) {
        printf("%d-->",s->data);
        s = s->next;
    }
    printf("Nul.\n");
}

int Length(LinkQueue *Q) {
    int len = 0;
    QueueNode *p = Q->front->next;
    while(p != NULL) {
        len++;
        p = p->next;
    }
    return len;
}

void ClearQueue(LinkQueue *Q) {
    if(Q->tail == Q->front) return;
    QueueNode *s = Q->front->next;
    while(s != NULL) {
        Q->front->next = s->next;
        free(s);
        s = Q->front->next;
    }
    Q->tail = Q->front;
}

void DestroyQueue(LinkQueue *Q) {
    ClearQueue(Q);
    free(Q->front);
    Q->front = Q->tail = NULL;
}
