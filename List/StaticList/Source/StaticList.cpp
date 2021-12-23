#include "StaticList.h"

#define swap(a, b) \
_type(a) temp = a; \
a = b; \
b = temp; 

int Malloc_SL(StaticList &space) {
    int i = space[1].cur;
    if(space[1].cur != 0)
        space[1].cur = space[i].cur;
    return i;
}

void InitStaticList(StaticList &space) {
    space[0].cur = -1;
    for (int i = 1; i < MAX_SIZE - 1; i++) {
        space[i].cur = i + 1;
    }
    space[MAX_SIZE-1].cur = 0;
}

void Insert(StaticList &space, ElemType x) {
    int i = Malloc_SL(space);
    if(i == 0) {
        printf("静态链表空间不足！\n");
        return;
    }

    space[i].data = x;
    space[i].cur = space[0].cur;
    space[0].cur = i;
}

void Delete(StaticList &space) {
    int i = space[0].cur;
    if(i == -1) {
        printf("静态链表为空！\n");
        return;
    }

    space[0].cur = space[i].cur;
    space[i].cur = space[1].cur;
    space[1].cur = i;
}

void ShowStaticList(StaticList &space) {
    int i = space[0].cur;
    while(i != -1) {
        printf("%c-->",space[i].data);
        i = space[i].cur;
    }
    printf("Nul.\n");
}