#include "SCList.h"

Node* _BuyNode(ElemType x) {
    Node *s = (Node *)malloc(sizeof(Node));
    assert(s != NULL);
    s->data = x;
    s->next = NULL;
    return s;
}

void InitSCList(List *list) {
    Node *s = (Node *)malloc(sizeof(Node));
    assert(s != NULL);
    list->first = list->last = s;
    list->last->next = list->last;
    list->size = 0;
}

void push_back(List *list, ElemType data) {
    Node* s = _BuyNode(data);
    list->last->next = s;
    list->last = s;
    s->next = list->first;

    list->size++;
}

void push_front(List *list, ElemType data) {
    Node* s = _BuyNode(data);
    s->next = list->first->next;
    list->first->next = s;
    if(list->first == list->last) {
        list->last = s;
    }
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
    if(list->first == list->last) {
        printf("循环链表为空。\n");
        return;
    }
    Node *p = list->first;

    while(p->next != list->last) {
        p = p->next;
    }
    free(list->last);
    list->last = p;
    list->last->next = list->first;
    list->size--;
}

void pop_front(List *list) {
    if(list->first == list->last) {
        printf("循环链表为空。\n");
        return;
    }
    Node *p = list->first->next;
    list->first->next = p->next;
    free(p);

    if(list->size-- == 1) {
        list->last = list->first;
    }
}

void insert_val(List *list, ElemType data) {
    Node *s = _BuyNode(data);
    Node *p = list->first;
    while(p->next != list->first && p->next->data < data) {
        p = p->next;
    }
    s->next = p->next;
    p->next = s;
    if(list->size++ == 0 || p == list->last) {
        list->last = s;
    }
}

PNode find(List *list, ElemType key) {
    if(list->size == 0)
        return NULL;
    Node *p = list->first->next;
    while(p != list->first && p->data != key) {
        p = p->next;
    }
    if(p == list->first)
        return NULL;
    else
        return p;
}

int lenght(List *list) {
    return list->size;
}

void delete_val(List *list, ElemType key) {
    if (list->first == list->last)
        return;
    
    Node *p = list->first;
    while(p->next != list->first && p->next->data != key) 
        p = p->next;
    if(p->next == list->first) {
        printf("要查找的数据%d不在链表中。\n", key);
        return;
    } else if(p->next == list->last) {
        list->last = p;
    }
    Node *s = p->next;
    p->next = s->next;
    free(s);
    list->size--;
}

void sort(List *list) {
    if(list->size == 0 || list->size == 1)
        return;
    Node *p = list->first->next;
    Node *q = p->next;
    list->last->next = NULL;
    list->last = p;
    p->next = list->first;

    while(q != NULL) {
        Node *s = q;
        q = q->next;
        p = list->first;
        while(p->next != list->first && p->next->data < s->data) {
            p = p->next;
        }
        s->next = p->next;
        p->next = s;
        if(p == list->last) {
            list->last = s;
        }
    }
}

void resver(List *list) {
    if(list->size == 0 || list->size == 1)
        return;

    Node *p = list->first->next;
    Node *q = p->next;
    list->last->next = NULL;
    list->last = p;
    p->next = list->first;

    while(q != NULL) {
        p = q;
        q = q->next;

        p->next = list->first->next;
        list->first->next = p;
    }
}

void clear(List *list) {
    Node *p = list->first->next;
    while(p != list->first) {
        list->first->next = p->next;
        free(p);
        p = list->first->next;
    }
    list->last->next = list->last = list->first;
    list->size = 0;
}

void destroy(List *list) {
    clear(list);
    free(list->first);
    list->first = list->last = NULL;
}