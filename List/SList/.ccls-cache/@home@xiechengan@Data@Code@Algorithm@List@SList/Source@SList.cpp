#include "SList.h"

void InitList(List *list) {
    list->first = list->last = (PNode)malloc(sizeof(Node));
    assert(list->first != NULL);
    list->first->next = NULL;
    list->size = 0;
}

void push_back(List *list, ElemType data) {
    PNode p = (PNode)malloc(sizeof(Node));
    if(p == NULL) {
        printf("创建节点失败，内存不足。\n");
        return;
    }
    p->data = data;
    p->next = NULL;

    list->last = list->last->next = p;

    list->size++;

}

void show_list(List *list) {
    PNode p = list->first->next;
    while(p != NULL) {
        printf("%d-->", p->data);
        p = p->next;
    }
    printf("Nul.\n");
}

void push_front(List *list, ElemType data) {
    PNode p = (PNode)malloc(sizeof(Node));
    if(p == NULL) {
        printf("创建节点失败，内存不足。\n");
        return;
    }
    p->data = data;

    p->next = list->first->next;
    list->first->next = p;
    if(list->size++ == 0) {
        list->last = p;
    }
}

void pop_back(List *list) {
    if(list->size == 0) {
        return;
    }

    PNode p = list->first;
    while(p->next != list->last)
        p = p->next;
    
    free(list->last);
    p->next = NULL;
    list->last = p;
    list->size--;
}

void pop_front(List *list) {
    if(list->size == 0) {
        return;
    }

    PNode p = list->first->next;
    list->first->next = p->next;
    free(p);
    if(--list->size == 0) {
        list->last = list->first;
    }
}

void insert_val(List *list, ElemType data) {
    PNode p = (PNode)malloc(sizeof(Node));
    if(p == NULL) {
        printf("创建节点失败，内存不足。\n");
        return;
    }
    p->data = data;

    PNode s = list->first;

    while(s->next != NULL && s->next->data < p->data) 
        s = s->next;

    if(s->next == NULL) {
        list->last = p;
    }

    p->next = s->next;
    s->next = p;
    
    list->size++;
}

PNode find(List *list, ElemType key) {
    if(list->size==0) {
        printf("链表为空。\n");
    }

    PNode p = list->first->next;
    while(p != NULL && p->data != key) 
        p = p->next;
    return p;
}

int lenght(List *list) {
    return list->size;
}

void delete_val(List *list, ElemType key) {
    if(list->size==0) {
        printf("链表为空。\n");
        return;
    }

    PNode p = find(list, key);
    if(p == NULL) {
        printf("要删除的数据%d不在链表中。\n", key);
        return;
    }

    if(list->last == p) {
        pop_back(list);
    } else {
        PNode q = p->next;
        p->data = q->data;
        p->next = q->next;
        free(q);
    }
    list->size--;
}

void sort(List *list) {
    if(list->size==0 || list->size==1) return;

    PNode s = list->first->next;
    PNode q = s->next;

    list->last = s;
    list->last->next = NULL;

    while(q != NULL) {
        s = q;
        q = q->next;

        PNode p = list->first;
        while(p->next != NULL && p->next->data < s->data)
            p = p->next;

        if(p->next == NULL) {
            list->last = s;
        }

        s->next = p->next;
        p->next = s;

    }
}

void resver(List *list) {
    if(list->size == 0 && list->size == 1) return;

    PNode s = list->first->next;
    PNode q = s->next;

    list->last = s;
    list->last->next = NULL;

    while(q != NULL) {
        s = q;
        q = q->next;

        s->next = list->first->next;
        list->first->next = s;        
    }
}

void clear(List *list) {
    PNode p = list->first->next;
    while(p != NULL) {
        list->first->next = p->next;
        free(p);
        p = list->first->next;
    }

    list->last = list->first;
    list->size = 0;
}

void destroy(List *list) {
    clear(list);
    free(list->first);
    list->last = list->first = NULL;
}
