#include "HString.h"

void InitString(HString *S) {
    S->ch = NULL;
    S->length = 0;
}

void StrAssign(HString *S, const char *str) {
    int len = strlen(str);
    if (S->ch != NULL)
        free(S->ch);
    S->ch = (char*)malloc(sizeof(char)*len);
    assert(S->ch != NULL);
    for (int i=0; i<len; i++) {
        S->ch[i] = str[i];
    }
    S->length = len;
}

void PrintString(HString *S) {
    for (int i=0; i<S->length; i++) {
        putchar(S->ch[i]);
    }
    printf("\n");
}

int StrLength(HString *S) {
    return S->length;
}

void StrCopy(HString *S, HString *T) {
    int len = StrLength(T);
    if(S->ch != NULL)
        free(S->ch);
    S->ch = (char*)malloc(sizeof(char)*len);
    assert(S->ch != NULL);
    for (int i=0; i<len; i++) {
        S->ch[i] = T->ch[i];
    }
    S->length = len;
}

bool StrEmpty(HString *S) {
    return S->length == 0;
}

int StrCompare(HString *S, HString *T) {
    if(S->length == 0 && T->length == 0)
        return 0;
    int result = 0;
    int i=0;
    int j=0;
    while(i++<S->length && j++<T->length) {
      if(S->ch[i] > T->ch[i])
          return 1;
      else if(S->ch[i] < T->ch[i])
          return -1;
    }
    if(i < S->length)
        result = 1;
    else if(j < T->length)
        result = -1;
    return result;
}

void StrConcat(HString *T, HString *s1, HString *s2) {
    if(T->ch != NULL)
        free(T->ch);
    int len1 = StrLength(s1);
    int len2 = StrLength(s2);
    T->ch = (char*)malloc(sizeof(char)*(len1+len2));
    assert(T->ch != NULL);
    for(int i = 0; i<len1; i++)
        T->ch[i] = s1->ch[i];
    for(int i = 0; i<len2; i++)
        T->ch[i+len1] = s2->ch[i];
    T->length = len1+len2;
}

void SubString(HString *S, HString *sub, int pos, int len) {
    if(pos < 0 || pos> S->length || len < 0 || len+pos>S->length)
        return;
    if(sub->ch != NULL)
        free(sub->ch);
    sub->ch = (char*)malloc(sizeof(char)*len);
    for(int i = 0; i<len; i++)
        sub->ch[i] = S->ch[pos+i];
    sub->length = len;
}

void StrInsert(HString *S, int pos, HString *T) {
    if(pos<0 || pos > S->length || T->length == 0)
        return;
    char *ch = (char*)realloc(S->ch, sizeof(char)*(S->length+T->length));
    assert(ch != NULL);
    S->ch = ch;
    for(int i=S->length-1; i >= pos; i--)
        S->ch[T->length+i] = S->ch[i];
    for(int i=0; i < T->length; i++)
        S->ch[i+pos] = T->ch[i];
    S->length += T->length;
}

void StrDelete(HString *S, int pos, int len) {
   if(pos<0 || pos>S->length || len<0)
       return;
   if(S->length-pos < len)
       len = S->length - pos;
   assert(S->ch !=NULL);
   for(int i=0; i<S->length-pos-len;i++)
       S->ch[i+pos] = S->ch[i+pos+len];

   S->length -= len;
}

void StrClear(HString *S) {
    S->length = 0;
    if(S->ch != NULL)
        free(S->ch);
    S->ch = NULL;
}

int StrIndex(HString *S, HString *T, int pos) {
    int i = pos, j = 0;
    while(S->ch[i] != '\0' && T->ch[j] != '\0') {
        if (S->ch[i] == T->ch[j]) {
            i++;
            j++;
        } else {
            i = i-j+1;
            j = 0;
        }
    }
    if(T->ch[j] == '\0')
        return i-j;
    return -1;
}

void StrReplace(HString *S, HString *T, HString *V) {
    int s_len = StrLength(S);
    int t_len = StrLength(T);
    int v_len = StrLength(V);

    int pos = 0;
    int index = -1;
    while(pos < s_len) {
        index = StrIndex(S, T, pos);
        if (index == -1)
            return;
        StrDelete(S, index, t_len);
        StrInsert(S, index, V);
        pos = index + v_len;
    }
}
