#include "SparseMatrix.h"

void CreateMatrix(SMatrix *M, const char* path) {
    FILE *fp = fopen(path, "r");
    if(fp == NULL)
        exit(1);
    fscanf(fp, "%d %d", &M->mu, &M->nu);

    ElemType value;
    int k=0;
    for(int i=0; i < M->mu; i++) {
        for(int j = 0; j < M->nu; j++) {
            fscanf(fp, "%d", &value);
            if(value != 0) {
                M->data[k].i = i;
                M->data[k].j = j;
                M->data[k].e = value;
                k++;
            }
        }
    }
    M->tu = k;

    fclose(fp);
}

void PrintMatrix(SMatrix *M) {
    printf("row=%d, col=%d\n", M->mu, M->nu);
    for(int i = 0; i < M->tu; i++) {
        printf("(%d, %d, %d)\n", M->data[i].i, M->data[i].j, M->data[i].e);
    }
}

void CopyMatrix(SMatrix *M, SMatrix *T) {
    T->mu = M->mu;
    T->nu = M->nu;
    T->tu = M->tu;
    for (int i=0; i<T->tu; i++) {
        T->data[i].i = M->data[i].i;
        T->data[i].j = M->data[i].j;
        T->data[i].e = M->data[i].e;
    }
}

void AddMatrix(SMatrix *M, SMatrix *N, SMatrix *T) {
    if (M->mu != N->mu || M->nu != N->nu)
        return;
    T->mu = M->mu;
    T->nu = M->nu;
    int mlen, nlen, tlen;
    mlen = nlen = tlen = 0;
    ElemType value;
    for (int i=0; i<T->mu; i++) {
        for (int j=0; j<T->nu; j++) {
            value = 0;
            if (M->data[mlen].i == i && M->data[mlen].j == j)
                value += M->data[mlen++].e;
            if (N->data[nlen].i == i && N->data[nlen].j == j)
                value += N->data[nlen++].e;
            if(value != 0) {
                T->data[tlen].i = i;
                T->data[tlen].j = j;
                T->data[tlen].e = value;
                tlen++;
            }
        }
    }
    T->tu = tlen;
}

void SubMatrix(SMatrix *M, SMatrix *N, SMatrix *T) {
    if (M->mu != N->mu || M->nu != N->nu)
        return;
    T->mu = M->mu;
    T->nu = M->nu;
    int mlen, nlen, tlen;
    mlen = nlen = tlen = 0;
    ElemType value;
    for (int i=0; i<T->mu; i++) {
        for (int j=0; j<T->nu; j++) {
            value = 0;
            if (M->data[mlen].i == i && M->data[mlen].j == j)
                value = M->data[mlen++].e;
            if (N->data[nlen].i == i && N->data[nlen].j == j)
                value -= N->data[nlen++].e;
            if(value != 0) {
                T->data[tlen].i = i;
                T->data[tlen].j = j;
                T->data[tlen].e = value;
                tlen++;
            }
        }
    }
    T->tu = tlen;
}

ElemType GetMatrixValue(SMatrix *M, int row, int col) {
    for(int i = 0; i<M->tu; i++) {
        if(M->data[i].i == row && M->data[i].j == col)
            return M->data[i].e;
    }
    return 0;
}

void MulMatrix(SMatrix *M, SMatrix *N, SMatrix *T) {
    if (M->mu != N->nu || M->nu != N->mu)
        return;
    T->mu = M->mu;
    T->nu = M->nu;

    int index = 0;
    ElemType value;

    for (int i = 0; i<M->mu; i++) {
        for (int j = 0; j<M->nu; j++) {
            value = 0;
            for (int k = 0; k<M->nu; k++) {
                value += GetMatrixValue(M, i, k) * GetMatrixValue(N, k, j);
            }
            if(value != 0) {
                T->data[index].i = i;
                T->data[index].j = j;
                T->data[index].e = value;
                index++;
            }
        }
    }
    T->tu = index;
}

void TransposeMatrix(SMatrix *M, SMatrix *T) {
    T->mu = M->nu;
    T->nu = M->mu;
    T->tu = M->tu;

    int k = 0;
    if(T->tu != 0) {
        for (int col = 0; col<M->nu; col++) {
            for (int i = 0; i<M->tu; i++) {
                if(M->data[i].j == col) {
                    T->data[k].i = M->data[k].j;
                    T->data[k].j = M->data[k].i;
                    T->data[k].e = M->data[k].e;
                    k++;
                }
            }
        }
    }
}

void FastTransposeMatrix(SMatrix *M, SMatrix *T) {
    T->tu = M->tu;
    T->mu = M->nu;
    T->nu = M->mu;
    int *num = (int *)malloc(sizeof(int)*M->nu);
    memset(num,0,sizeof(int)*M->nu);
    for(int i=0; i<M->tu; i++) {
        num[M->data[i].j]++;
    }
    int *slist = (int *)malloc(sizeof(int)*M->nu);
    slist[0] = 0;
    for(int i=1; i<M->nu; i++) {
        slist[i] = slist[i-1] + num[i-1];
    }

    for(int i=0; i<M->tu; i++) {
        int *index = &slist[M->data[i].j];
        T->data[*index].e = M->data[i].e;
        T->data[*index].i = M->data[i].j;
        T->data[*index].j = M->data[i].i;
        (*index)++;
    }
}
