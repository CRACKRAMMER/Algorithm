#ifndef __GENLIST_H__
#define __GENLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

typedef int AtomType;
typedef enum{HEAD,ATOM,CHILDLIST} ElemTag;

typedef struct GLNode {
    ElemTag tag;
    union {
        AtomType atom;
        GLNode *hp;
    };
    GLNode *tp;
} GLNode;

typedef GLNode* GenList;

void InitGenList(GenList *gl);
void CreateGenList(GenList *gl, const char *str);
void PrintGenList(GenList gl);
bool GenListEmpty(GenList gl);
int GenListLength(GenList gl);
int GenListDepth(GenList gl);

#endif //__GENLIST_H__
