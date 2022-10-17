#ifndef __SPARSEMATRIX_H__
#define __SPARSEMATRIX_H__

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define ElemType int
#define MAXSIZE 100
typedef struct Triple {
    int i;
    int j;
    ElemType e;
} Triple;

typedef struct SMatrix {
    Triple data[MAXSIZE];
    int mu;
    int nu;
    int tu;
}SMatrix;

void CreateMatrix(SMatrix *M, const char* path);
void PrintMatrix(SMatrix *M);
void CopyMatrix(SMatrix *M, SMatrix *T);
void AddMatrix(SMatrix *M, SMatrix *N, SMatrix *T);
void SubMatrix(SMatrix *M, SMatrix *N, SMatrix *T);
void MulMatrix(SMatrix *M, SMatrix *N, SMatrix *T);
void TransposeMatrix(SMatrix *M, SMatrix *T);
void FastTransposeMatrix(SMatrix *M, SMatrix *T);

#endif //__SPARSEMATRIX_H__
