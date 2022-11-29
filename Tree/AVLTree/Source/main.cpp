#include "AVLTree.h"

int main(int argc, char *argv[]) {
    DataType ar[] = {30,20,10};
    int n = sizeof(ar)/sizeof(DataType);
    AVLTree avt;
    initAVLTree(&avt);

    for(int i=0; i<n; i++) {
        insertAVL(&avt, ar[i]);
    }

    return 0;
}
