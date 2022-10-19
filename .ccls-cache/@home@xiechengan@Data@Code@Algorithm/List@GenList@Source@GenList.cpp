#include "GenList.h"

void InitGenList(GenList *gl) {
    *gl = NULL;
}

// char *gb = "(1,(2,3))";

bool sever(char *sub, char *hsub) {
    if(*sub=='\0' || strcmp(sub, "()")==0) {
        hsub[0] = '\0';
        return true;
    }
    int n = strlen(sub);
    int i = 0;
    int k = 0;
    while(i<n && (sub[i]!=',' || k!=0)) {
        if(sub[i]=='(') {
            k++;
        } else if (sub[i]==')') {
            k--;
        }
        i++;
    }
    if(k==0) {
        sub[i] = '\0';
        strcpy(hsub, sub);
        if(i<n) {
            strcpy(sub, sub+i+1);
        } else {
            sub[0] = '\0';
        }
    } else {
        return false;
    }
    return true;
}

void CreateGenList(GenList *gnl, const char *str) {
    GenList gl = *gnl;
    int n = strlen(str);
    char *sub = (char*)malloc(sizeof(char)*n);
    char *hsub = (char*)malloc(sizeof(char)*n);
    assert(sub!=NULL && hsub !=NULL);

    strncpy(sub, str+1, n-2);
    sub[n-2] = '\0';

    if(gl == NULL) {
        gl = (GLNode *)malloc(sizeof(GLNode));
        assert(gl !=NULL);
        gl->tag = HEAD;
        gl->hp = gl->tp = NULL;
    }

    GLNode *p = gl;
    while(strlen(sub) != 0) {
        p = p->tp = (GLNode*)malloc(sizeof(GLNode));
        assert(p!=NULL);
        p->hp = p->tp = NULL;

        if(sever(sub, hsub)) {
            if(hsub[0]=='(') {
                p->tag = CHILDLIST;
                CreateGenList(&p->hp, hsub);
            } else {
                p->tag = ATOM;
                p->atom = atoi(hsub);
            }
        }
    }
    *gnl = gl;
}

void ShowGenList(GenList gl) {
    printf("(");
    while(gl != NULL) {
        if(gl->tag != HEAD) {
            if(gl->tag == ATOM) {
                printf("%d", gl->atom);
            } else if(gl->tag == CHILDLIST) {
                ShowGenList(gl->hp);
            }
            if(gl->tp != NULL) {
                printf(",");
            }
        }
        gl = gl->tp;
    }
    printf(")");
}

void PrintGenList(GenList gl) {
    ShowGenList(gl);
    printf("\n");
}

bool GenListEmpty(GenList gl) {
    return gl->tp==NULL;
}

int GenListLength(GenList gl) {
    int length = 0;
    while(gl->tp != NULL) {
        length++;
        gl = gl->tp;
    }
    return length;
}

int GenListDepth(GenList gl) {
    int maxdepth = 0;
    while(gl!=NULL) {
        if(gl->tag == CHILDLIST) {
            int depth = GenListDepth(gl->hp);
            if(maxdepth<depth) {
                maxdepth = depth;
            }
        }
        gl = gl->tp;
    }

    return maxdepth + 1;
}
