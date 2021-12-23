#include "SString.h"

int main(int argc, char *argv[]) {
    SString S;
    InitString(S);

    char *str = "abcdefg";
    StrAssign(S, str);

    return 0;
}