#include "BST.h"

int main(int argc, char *argv[]) {
    ElemType data[] = {45,12,53,3,37,100,24,61,90,78};
    int n = sizeof(data)/sizeof(ElemType);
    BST bst;
    InitBSTree(&bst);
    for(int i=0; i<n; i++) {
        insertBSTree(&bst, data[i]);
    }

    Sort(&bst);
    RemoveBSTree(&bst, 78);
    RemoveBSTree(&bst, 45);
    Sort(&bst);

    return 0;
}
