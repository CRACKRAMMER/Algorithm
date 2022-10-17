#include "SparseMatrix.h"

int main(int argc, char *argv[]) {
    SMatrix M, N, T;
    memset(&M, 0, sizeof(SMatrix));
    memset(&N, 0, sizeof(SMatrix));
    memset(&T, 0, sizeof(SMatrix));
    CreateMatrix(&M, "2.txt");
    PrintMatrix(&M);
//    CreateMatrix(&N, "3.txt");
//    PrintMatrix(&N);
//    MulMatrix(&M, &N, &T);
    FastTransposeMatrix(&M, &T);
    PrintMatrix(&T);
//    SubMatrix(&M, &N, &T);
//    PrintMatrix(&T);

    return 0;
}
