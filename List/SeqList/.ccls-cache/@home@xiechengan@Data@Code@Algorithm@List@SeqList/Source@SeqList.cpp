#include "SeqList.h"

bool Inc(SeqList *list) {
    ElemType *temp = (ElemType *)realloc(list->base, sizeof(ElemType) * (list->capacity + INC_SIZE));
    if(temp == NULL) {
        printf("增加空间失败，内存不足。\n");
        return false;
    }

    list->capacity += INC_SIZE;
    return true;
}

void InitSeqList(SeqList *list) {
    list->base = (ElemType *)malloc(sizeof(ElemType) * SEQLIST_INIT_SIZE);
    assert(list != NULL);
    list->capacity = SEQLIST_INIT_SIZE;
    list->size = 0;
}

void push_back(SeqList *list, ElemType x) {
    if(list->size >= list->capacity && !Inc(list)) {
        printf("顺序表空间已满，%d不能尾部插入数据。\n", x);
        return;
    }

    list->base[list->size++] = x;
}

void push_front(SeqList *list, ElemType x) {
    if(list->size >= list->capacity && !Inc(list)) {
        printf("顺序表空间已满，不能头部插入数据。\n");
        return;
    }

    for (int i = list->size; i > 0; i--) {
        list->base[i] = list->base[i-1];
    }

    list->base[0] = x;
    list->size++;
}

void show_list(SeqList *list) {
    for(int i = 0; i < list->size; i++) {
        printf("%d ", list->base[i]);
    }
    printf("\n");
}

void pop_back(SeqList *list) {
    if(list->size == 0) {
        printf("顺序表空间为空，不能尾部删除数据。\n");
        return;
    }
    list->size--;
}

void pop_front(SeqList *list) {
    if(list->size == 0) {
        printf("顺序表空间为空，不能尾部删除数据。\n");
        return;
    }

    for(int i = 1; i < list->size; i++) {
        list->base[i-1] = list->base[i];
    }
    list->size--;
}

void insert_pos(SeqList *list, int pos, ElemType x) {
    if(pos < 0 || pos > list->size) {
        printf("插入数据的位置非法，不能插入数据。\n");
        return;
    }

    if(list->size >= list->capacity && !Inc(list)) {
        printf("顺序表空间已满，不能按位置插入数据。\n");
        return;
    }

    for(int i = list->size; i > pos; i++) {
        list->base[i] = list->base[i-1];
    }

    list->base[pos] = x;
    list->size++;
}

int find(SeqList *list, ElemType key) {
    for(int i = 0; i < list->size; i++) {
        if(list->base[i] == key) {
            return i;
        }
    }
    return -1;
}

int lenght(SeqList *list) {
    return list->size;
}

void delete_pos(SeqList *list, int pos) {
    if(pos < 0 || pos >= list->size) {
        printf("删除数据的位置非法，不能删除数据。\n");
        return;
    }

    for(int i = pos; i < list->size - 1; i++) {
        list->base[i] = list->base[i+1];
    }

    list->size--;
}

void delete_val(SeqList *list, ElemType x) {
    // for(int i = 0; i < list->size; i++) {
    //     if(list->base[i] == data) {
    //         delete_pos(list, i);
    //     }
    // }

    int pos = find(list, x);
    if(pos == -1) {
        printf("查找的数据%d在顺序表中不存在。\n", x);
        return;
    } 
    delete_pos(list, pos);
}

void sort(SeqList *list) {
    // int i, j;
    // for(i = 1; i < list->size; i++) {
    //     for(j = i; j > 0; j--) {
    //         if(list->base[i] > list->base[j-1]) {
    //             break;
    //         }
    //     }

    //     ElemType temp = list->base[i];

    //     for(int k = i; k > j; k--) {
    //         list->base[k] = list->base[k-1];
    //     }

    //     list->base[j] = temp;
    // }

    for (int i = 1; i < list->size; i++) {
        int pos = i - 1;
        ElemType temp = list->base[i];

        while(list->base[pos] > temp && pos >= 0) {
            list->base[pos+1] = list->base[pos];
            pos--;
        }

        list->base[pos+1] = temp;
    }
}

void resver(SeqList *list) {
    for(int i = 0; i < list->size/2; i++) {
        ElemType temp = list->base[i];
        list->base[i] = list->base[list->size - i - 1];
        list->base[list->size - i - 1] = temp;
    }
}

void clear(SeqList *list) {
    list->size = 0;
}

void destroy(SeqList *list) { 
    free(list->base);
    list->base = NULL;
    list->size = 0;
    list->capacity = 0;
}