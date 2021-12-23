#include "LinkStack.h"

void InitStack(LinkStack *st) {
    *st = NULL;
}

LinkStack BuyNode(ElemType data) {
    LinkStack s = (LinkStack)malloc(sizeof(StackNode));
    if(s == NULL) return NULL;
    s->data = data;
    s->next = NULL;
    return s;
}

int Push(LinkStack *st, ElemType data) {
    LinkStack s = BuyNode(data);
    if(s == NULL) return -1;
    s->next = *st;
    *st = s;
    return 0;
}

int Pop(LinkStack *st, ElemType *data) {
    if(*st == NULL) return -1;
    *data =  (*st)->data;
    LinkStack s = *st;
    (*st) = (*st)->next;
    free(s);
    return 0;
}

void Show(LinkStack *st) {
    LinkStack s = *st;
    while(s != NULL) {
        printf("\t%d\n", s->data);
        s = s->next;
    }
    printf("\n");
}

int Length(LinkStack *st) {
    LinkStack s = *st;
    int i = 0;
    while(s != NULL) {
        i++;
        s = s->next;
    }
    return i;
}

void Clear(LinkStack *st) {
    LinkStack s;
    while(*st != NULL) {
        s = *st;
        *st = (*st)->next;
        free(s);
    }
}

void _print(StackNode *st) {
    if(st == NULL) return;
    _print(st->next);
    printf("%c", st->data);
}

void Print(LinkStack *st) {
    _print(*st);
    printf("\n");
}

void Destroy(LinkStack *st) {
    Clear(st);
}