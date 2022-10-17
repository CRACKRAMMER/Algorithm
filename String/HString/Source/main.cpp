#include "HString.h"

int main(int argc, char *argv[]) {
    HString S;
    InitString(&S);
    StrAssign(&S, "ababcababcab");

    HString T;
    InitString(&T);
    StrAssign(&T, "abc");

    HString V;
    InitString(&V);
    StrAssign(&V, "xyz");

    StrReplace(&S, &T, &V);
    PrintString(&S);
    return 0;
}
