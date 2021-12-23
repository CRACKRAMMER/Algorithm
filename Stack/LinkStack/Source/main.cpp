#include "LinkStack.h"

int main(int argc, char *argv[]) {
    LinkStack st;
    InitStack(&st);

    ElemType data;

    for(int i = 1; i <= 5; i++) {
        Push(&st, i);
    }

    Show(&st);
    Pop(&st, &data);
    Show(&st);
    printf("%d\n", Length(&st));

    Destroy(&st);
    return 0;
}