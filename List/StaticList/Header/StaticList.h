#ifndef __STATICLIST_H__
#define __STATICLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_SIZE 20

typedef char ElemType;

typedef struct ListNode {
    ElemType data;
    int cur;
}ListNode;

typedef ListNode StaticList[MAX_SIZE];

int Malloc_SL(StaticList &space);
void InitStaticList(StaticList &space);
void Insert(StaticList &space, ElemType x);
void ShowStaticList(StaticList &space);
void Delete(StaticList &space);

#endif // __STATICLIST_H__