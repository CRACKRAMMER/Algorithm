#ifndef __DCLIST_H__
#define __DCLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int ElemType;

typedef struct Node {
    ElemType data;
    struct Node *prio;
    struct Node *next;
}Node, *PNode;

typedef struct List {
    PNode first;
    PNode last;
    int size;
}List;

Node *_BuyNode(ElemType x);
void InitDCList(List *list);

void push_back(List *list, ElemType data);
void show_list(List *list);
void push_front(List *list, ElemType data);
void pop_back(List *list);
void pop_front(List *list);
void insert_val(List *list, ElemType data);
PNode find(List *list, ElemType key);
int lenght(List *list);
void delete_val(List *list, ElemType key);
void sort(List *list);
void resver(List *list);
void clear(List *list);
void destroy(List *list);

#endif // __DCLIST_H__