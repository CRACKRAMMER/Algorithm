#include "DCList.h"

Node *_BuyNode(ElemType x) {
    Node *s = (PNode)malloc(sizeof(Node));
    s->data = x;
    s->next = s->prio = NULL;

    return s;
}

void InitDCList(List *list) {
    Node *s = (PNode)malloc(sizeof(Node));
    assert(s != NULL);
    s->data = -1;
    list->first = list->last = s;
    s->next = s->prio = s;
    list->size = 0;
}

void push_back(List *list, ElemType data) {
    Node *s = _BuyNode(data);

    list->first->prio = s;
    s->next = list->first;
    s->prio = list->last;
    list->last = list->last->next = s;
    list->size++;
}

void push_front(List *list, ElemType data) {
    Node *s = _BuyNode(data);

    s->next = list->first->next;
    s->prio = list->first;
    list->first->next = s;
    s->next->prio = s;
    if(list->first == list->last) list->last = s;
    list->size++;
}

void show_list(List *list) {
    Node *p = list->first->next;
    while(p != list->first) {
        printf("%d-->", p->data);
        p = p->next;
    }
    printf("Nul.\n");
}

void pop_back(List *list) {
    if(list->first == list->last) return;

    list->last->prio->next = list->last->next;
    list->first->prio = list->last->prio;
    free(list->last);
    list->last = list->first->prio;
    list->size--;
}

void pop_front(List *list) {
    if(list->first == list->last) return;

    Node *p = list->first->next;
    list->first->next = p->next;
    p->next->prio = list->first;
    if(p == list->last) list->last = list->first;
    free(p);
    list->size--;
}

void insert_val(List *list, ElemType data) {
    Node *s = _BuyNode(data);
    Node *p = list->first;
    while(p->next != list->first && p->next->data < data) p = p->next;

    s->next = p->next;
    s->prio = p;
    p->next = s;
    s->next->prio = s;

    if(p == list->last) list->last = s;
    list->size++;
}

PNode find(List *list, ElemType key) {
    Node *p = list->first->next;
    while(p != list->first && p->data != key) p = p->next;
    if(p == list->first) return NULL;
    else return p;
}

int lenght(List *list) {
    return list->size;
}

void delete_val(List *list, ElemType key) {
    Node *p = find(list, key);
    if(p == NULL) {
        printf("要删除的数据%d不存在。\n", key);
        return;
    }

    p->prio->next = p->next;
    p->next->prio = p->prio;
    
    if(p == list->last) list->last = p->prio;
    free(p);
    list->size--;
}

void sort(List *list) {
    if(list->size == 0 || list->size == 1) return;

    Node *p = list->first->next;
    Node *q = p->next;

    list->last->next = NULL;
    p->next = list->first;
    list->first->prio = list->last = p;

    while(q != NULL) {
        Node *s = q;
        q = q->next;
        p = list->first;
        while(p->next != list->first && p->next->data < s->data) p = p->next;

        s->next = p->next;
        s->prio = p;
        p->next = s;
        s->next->prio = s;
        if(p == list->last) list->last = s;
    }
}

void resver(List *list) {
    if(list->size == 0 || list->size == 1) return;

    Node *p = list->first->next;
    Node *q = p->next;

    list->last->next = NULL;
    p->next = list->first;
    list->first->prio = list->last = p;

    while(q != NULL) {
        p = q;
        q = q->next;

        p->next = list->first->next;
        p->prio = list->first;
        list->first->next = p;
        p->next->prio = p;
    }
}

void clear(List *list) {
    Node *p = list->first->next;
    while(p != list->first) {
        list->first->next = p->next;
        free(p);
        p = list->first->next;
    }
    list->last->next = list->last = list->first->prio = list->first;
    list->size = 0;
}

void destroy(List *list) {
    clear(list);
    free(list->first);
    list->first = list->last = NULL;
}