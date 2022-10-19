#include "BinTree.h"

int main(int argc, char *argv[]) {
    BinTree tree;
    InitBinTree(&tree, '#');
    const char *str = "ABC##DE##F##G#H##";
    const char *VLR = "ABCDEFGH";
    const char *LVR = "CBEDFAGH";
    const char *LRV = "CEFDBHGA";
    CreateBinTreeByPost(&tree, LRV, LVR);
    PreOrderIteration(&tree);
    printf("Size = %d\n", SizeBinTree(&tree));
    printf("Height = %d\n", HeightBinTree(&tree));
    //ElemType ch = 'H';
    //BinTreeNode *node = SearchBinTree(&tree, ch);
    //if(node) {
    //    printf("Search %c = %c\n", ch, node->data);
    //    BinTreeNode *parent = ParentBinTree(&tree, node);
    //    printf("Parent %c = %c\n", ch, parent->data);
    //}
    //else
    //    printf("Not Found!\n");
    //BinTree ctree;
    //InitBinTree(&ctree, '#');
    //CopyBinTree(&ctree, &tree);
    //PreOrder(&ctree);
    //ClearBinTree(&tree);
    //PreOrder(&tree);

    return 0;
}
