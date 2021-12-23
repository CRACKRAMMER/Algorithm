#include "SeqStack.h"

int main(int argc, char *argv[]) {
    SeqStack st;
    InitStack(&st);
    ElemType data;

    for(int i = 1; i <= 10; i++) {
        if(Push(&st, i) == -1) printf("栈满！无法入栈。\n");
    }

    Show(&st);

    for(int i = 1; i <= 5; i++) {
        if(Pop(&st, &data) == -1) printf("栈空！无法出栈。\n");
    }

    Show(&st);

    Destroy(&st);

    return 0;
}