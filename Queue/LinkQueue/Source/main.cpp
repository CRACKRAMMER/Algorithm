#include "LinkQueue.h"

int main(int argc, char *argv[]) {
    LinkQueue Q;
    InitQueue(&Q);
    ElemType data;

    for(int i = 1; i <= 10; i++) {
        if(EnQueue(&Q, i) != 0) break;
    }
    ShowQueue(&Q);
    for(int i = 1; i <= 5; i++) {
        if(DeQueue(&Q, &data) != 0) break;
        printf("%d已出队。\n", data);
    }
    ShowQueue(&Q);
    printf("Len = %d.\n", Length(&Q));
    DestroyQueue(&Q);
    return 0;
}