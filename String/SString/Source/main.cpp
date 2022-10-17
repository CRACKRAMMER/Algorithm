#include "SString.h"

int main(int argc, char *argv[]) {
        SString S;
        InitString(S);
        StrAssign(S, "ababcababcab");

        SString T;
        InitString(T);
        StrAssign(T, "abc");

        SString V;
        InitString(V);
        StrAssign(V, "xyz");

        StrReplace(S, T, V);
        PrintString(S);

        return 0;
}
