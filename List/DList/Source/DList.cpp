#include "DList.h"

Node *_BuyNode(ElemType x) {
    Node *s = (Node *)malloc(sizeof(Node));
    assert(s != NULL);
    s->data = x;
    s->next = s->prio = NULL;

    return s;
}

void InitDList(List *list) {
    Node *s = (Node *)malloc(sizeof(Node));
    assert(s != NULL);
    list->first = list->last = s;
    list->first->prio = NULL;
    list->first->next = NULL;
    list->size = 0;
}

void push_back(List *list, ElemType data) {
    Node *s = _BuyNode(data);
    s->next = list->last->next;
    s->prio = list->last;
    list->last = list->last->next = s;
    list->size++;
}

void push_front(List *list, ElemType data) {
    Node *s = _BuyNode(data);
    s->next = list->first->next; 
    s->prio = list->first;
    list->first->next = s;
    if(list->size++ == 0) {
        list->last = s;
    } else {
        s->next->prio = s;
    }
}

void show_list(List *list) {
    Node *p = list->first->next;
    while(p != list->last->next) {
        printf("%d-->", p->data);
        p = p->next;
    }
    printf("Nul.\n");
}

void pop_back(List *list) {
    if(list->size == 0) return;

    Node *p = list->last->prio;
    p->next = list->last->next;
    free(list->last);
    list->last = p;
    list->size--;
}

void pop_front(List *list) {
    if(list->size == 0) return;
    Node *p = list->first->next;
    list->first->next = p->next;
    if(list->first->next != NULL) {
        list->first->next->prio = list->first;
    } else {
        list->last = list->first;
    }
    free(p);
    list->size--;
}

void insert_val(List *list, ElemType data) {
    Node *s = _BuyNode(data);
    Node *p = list->first;

    while(p->next != NULL && p->next->data < data)
        p = p->next;
    
    s->next = p->next;
    s->prio = p;
    p->next = s;
    if(s->next != NULL) {
        s->next->prio = s;
    } else {
        list->last = s;
    }
    list->size++;
}

PNode find(List *list, ElemType key) {
    Node *p = list->first->next;
    while(p != NULL && p->data != key) p = p->next;
    return p;
}

int lenght(List *list) {
    return list->size;
}

void delete_val(List *list, ElemType key) {
    if(list->size == 0) return;

    Node *p = find(list, key);
    if(p == NULL) {
        printf("要查找的数据%d不在链表中。\n", key);
    }
    
    p->prio->next = p->next;
    if(p == list->last) {
        list->last = p->prio;
    } else {
        p->next->prio = p->prio;
    }
    free(p);
    list->size--;
}

void sort(List *list) {
    if(list->size == 0 || list->size == 1) return;

    Node *p = list->first->next;
    Node *q = p->next;
    list->last = p;
    list->last->next = NULL;

    while(q != NULL) {
        Node *s = q;
        q = q->next;
        p = list->first; 
        while(p->next != NULL && p->next->data < s->data) p = p->next;
        s->next = p->next;
        s->prio = p;
        p->next = s;
        if(s->next != NULL) {
            s->next->prio = s;
        } else {
            list->last = s;
        }
    }
}

void resver(List *list) {
    if(list->size == 0 || list->size == 1) return;

    Node *s = list->first->next;
    Node *q = s->next;
    list->last = s;
    list->last->next = NULL;

    while(q != NULL) {
        s = q;
        q = q->next;

        s->next = list->first->next;
        s->prio = list->first;
        list->first->next = s;
        s->next->prio = s;
    }
}

void clear(List *list) {
    Node *p = list->first->next;
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
    list->first = list->last = NULL;
}
