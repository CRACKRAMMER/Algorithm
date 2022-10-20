#include "CSTree.h"

int main(int argc, char *argv[]) {
    CSTree tree;
    InitCSTree(&tree, '#');
    CreateCSTree(&tree, "RAD#E##B#CFG#H#K#####");

    CSTreeNode *node;
    node = FindCSTree(&tree, 'B');
    node = ParentCSTree(&tree, node);

    return 0;
}
