#include "ThreadBinTree.h"

int main(int argc, char *argv[]) {
    const char *str = "ABC##DE##F##G#H##";
    BinTree tree;
    InitThreadBinTree(&tree, '#');
    CreateThreadBinTree(&tree, &str);
    ThreadBinTreeInOrder(&tree);

    BinTreeNode *node = ThreadBinTreeSearch(&tree, 'D');
    node = ThreadBinTreeParent(node);

    return 0;
}
