#include "../Header/SString.h"

void InitString(SString S) {
    S[0] = '\0';
}

void StrAssign(SString S, char *str) {

}

void StrCopy(SString S, SString T);
bool StrEmpty(SString S);
int StrCompare(SString S, SString T);
int StrLength(SString S);
void StrConcat(SString T, SString s1, SString s2);
void SubString(SString S, SString sub, int pos, int len);
void StrInsert(SString S, int pos, SString T);
void StrDelete(SString S, int pos, int len);
void StrClear(SString S);