#include "LinkStack.h"

LinkStack BuyStackNode(SType data);

void InitStack(LinkStack *st) {
    *st = NULL;
}

LinkStack BuyStackNode(SType data) {
    LinkStack s = (LinkStack)malloc(sizeof(StackNode));
    if(s == NULL) return NULL;
    s->data = data;
    s->next = NULL;
    return s;
}

int PushStack(LinkStack *st, SType data) {
    LinkStack s = BuyStackNode(data);
    if(s == NULL) return -1;
    s->next = *st;
    *st = s;
    return 0;
}

int PopStack(LinkStack *st, SType *data) {
    if(*st == NULL) return -1;
    *data =  (*st)->data;
    LinkStack s = *st;
    (*st) = (*st)->next;
    free(s);
    return 0;
}

int LengthStack(LinkStack *st) {
    LinkStack s = *st;
    int i = 0;
    while(s != NULL) {
        i++;
        s = s->next;
    }
    return i;
}

void ClearStack(LinkStack *st) {
    LinkStack s;
    while(*st != NULL) {
        s = *st;
        *st = (*st)->next;
        free(s);
    }
}

void DestroyStack(LinkStack *st) {
    ClearStack(st);
}
