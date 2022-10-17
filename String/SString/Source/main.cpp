#include "SString.h"

int main(int argc, char *argv[]) {
        SString s1;
        InitString(s1);
        StrAssign(s1, "abcde");

        SString s2;
        InitString(s2);
        StrAssign(s2, "abcdf");

        StrInsert(s1, 1, s2);
        printf("%s\n", s1);

        StrDelete(s1, 1, StrLength(s2));
        printf("%s\n", s1);

        StrClear(s1);
        printf("%s\n", s1);
}

// int main(int argc, char *argv[]) {
//     SString s1;
//     InitString(s1);
//     SString s2;
//     InitString(s2);
//
//     StrAssign(s1, "abcde");
//     StrAssign(s2, "abcdf");
//
//     SString T;
//     InitString(T);
//     StrConcat(T, s1, s2);
//     PrintString(T);
//
//     return 0;
// }
