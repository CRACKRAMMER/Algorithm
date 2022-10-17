#include "SString.h"

void InitString(SString S) {
    S[0] = '\0';
}

void StrAssign(SString S, char *str) {
    int len = strlen(str);
    for(int i = 0; i < len; ++i){
        S[i] = str[i];
    }
    S[len] = '\0';
}

void PrintString(SString S) {
    printf("%s\n", S);
}

void StrCopy(SString S, SString T) {
    int len = StrLength(T);
    for(int i = 0; i < len; ++i) {
        S[i] = T[i];
    }
    S[len] = '\0';
}

bool StrEmpty(SString S) {
    return S[0] == '\0';
}
int StrCompare(SString S, SString T) {
    int result = 0;
    while(*S!='\0' || *T!='\0') {
        result = *S-*T;
        if(result != 0)
            break;
        S++;
        T++;
    }
    if(result > 0)
        result =  1;
    else if(result < 0)
        result = -1;
    return result;
}
int StrLength(SString S) {
    int len = 0;
    while(*S != '\0') {
        len++;
        S++;
    }
    return len;
}
void StrConcat(SString T, SString s1, SString s2) {
    int len1 = StrLength(s1);
    int len2 = StrLength(s2);

    for(int i=0; i < len1; i++) {
        T[i] = s1[i];
    }

    int i;
    for(i=0; i < len2 && len1+i < MAXSTRLEN; i++) {
        T[len1+i] = s2[i];
    }
    T[len1+i] = '\0';

}
void SubString(SString S, SString sub, int pos, int len) {
    int slen = StrLength(S);
    if(pos < 0 || pos >= slen || len < 0 || len >= slen)
        return;
    int i;
    for (i = pos; i < len && S[i] != '\0'; i++) {
        sub[i-pos] = S[i];
    }
    sub[i-pos] = '\0';
}
void StrInsert(SString S, int pos, SString T) {
    int slen = StrLength(S);
    int tlen = StrLength(T);

    if(slen < pos || pos < 0 || MAXSTRLEN <= slen)
        return;

    if(slen+tlen > MAXSTRLEN)
        tlen = MAXSTRLEN-slen;

    for(int i = slen-1; i >= pos; i--) {
        S[i+tlen] = S[i];
    }
    for(int i = 0; i < tlen; i++) {
        S[i+pos] = T[i];
    }
    S[slen+tlen] = '\0';
}
void StrDelete(SString S, int pos, int len) {
    int slen = StrLength(S);
    if(pos < 0 || pos >= slen || len < 0)
        return;
    if(pos+len>=slen) {
        S[pos] = '\0';
    }
    int i;
    for(i = pos; i < slen-len; i++) {
        S[i] = S[i+len];
    }
    S[i] = '\0';
}
void StrClear(SString S) {
    S[0] = '\0';
}

int StrIndex(SString S, SString T, int pos) {
    int i = pos, j = 0;
    while(S[i] != '\0' && T[j] != '\0') {
        if (S[i] == T[j]) {
            i++;
            j++;
        } else {
            i = i-j+1;
            j = 0;
        }
    }
    if (T[j] == '\0')
        return i-j;
    return -1;
}

void StrReplace(SString S, SString T, SString V) {
    int s_len = StrLength(S);
    int t_len = StrLength(T);
    int v_len = StrLength(V);

    int index = -1;
    int pos = 0;

    while(pos < s_len) {
        index = StrIndex(S, T, pos);
        if (index == -1)
            return;
        StrDelete(S,index,t_len);
        StrInsert(S, index, V);
        pos = index + v_len;
    }
}
