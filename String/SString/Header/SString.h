#ifndef __SSTRING_H__
#define __SSTRING_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAXSTRLEN 20
#define u_char unsigned char

typedef u_char SString[MAXSTRLEN+1];
typedef int ElemType;

void InitString(SString S);
void PrintString(SString S);

void StrAssign(SString S, char *str);
void StrCopy(SString S, SString T);
bool StrEmpty(SString S);
int StrCompare(SString S, SString T);
int StrLength(SString S);
void StrConcat(SString T, SString s1, SString s2);
void SubString(SString S, SString sub, int pos, int len);
void StrInsert(SString S, int pos, SString T);
void StrDelete(SString S, int pos, int len);
void StrClear(SString S);

void StrIndex(SString S, SString T, int pos);
void StrReplace(SString S, SString T, SString V);

#endif // __SSTRING_H__
