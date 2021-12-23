#include "SeqStack.h"

void InitStack(SeqStack *st) {
    st->base = (ElemType *)malloc(sizeof(ElemType) * STACK_INIT_SIZE);
    assert(st->base != NULL);
    st->capacity = STACK_INIT_SIZE;
    st->top = 0;
}

bool Inc(SeqStack *st) {
    ElemType *newbase = (ElemType *)realloc(st->base, sizeof(ElemType) * (st->capacity + STACK_INC_SIZE));
    if(newbase == NULL) return false;
    st->base = newbase;
    st->capacity += STACK_INC_SIZE;
    return true;
}

bool IsFull(SeqStack *st) {
    return st->top >= st->capacity;
}

bool IsEmpty(SeqStack *st) {
    return st->top == 0;
}

int Push(SeqStack *st, ElemType data) {
    if(IsFull(st) && !Inc(st)) return -1;
    st->base[st->top++] = data;
    return 0;
}

int Pop(SeqStack *st, ElemType *data) {
    if(IsEmpty(st)) return -1;
    *data =  st->base[--st->top];
    return 0;
}

void Show(SeqStack *st) {
    for(int i = st->top-1; i >= 0 ; i--) {
        printf("\t%d\n", st->base[i]);
    }
    printf("\n");
}

int Length(SeqStack *st) {
    return st->top;
}

void Clear(SeqStack *st) {
    st->top = 0;
}

void Destroy(SeqStack *st) {
    free(st->base);
    st->base = NULL;
    st->capacity = st->top = 0;
}