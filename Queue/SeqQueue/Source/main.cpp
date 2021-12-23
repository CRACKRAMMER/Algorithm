#include "SeqQueue.h"

int main(int argc, char *argv[]) {
    Queue Q;
    InitQueue(&Q);
    ElemType data;

    for(int i = 1; i <= 7; i++) {
        if(EnQueue(&Q, i) != 0) break;
    }
    ShowQueue(&Q);
    for(int i = 1; i <= 6; i++) {
        if(DeQueue(&Q, NULL) != 0) break;
    }
    EnQueue(&Q, 8);
    ShowQueue(&Q);
    printf("Len = %d.\n", Length(&Q));

    DestroyQueue(&Q);
    return 0;
}