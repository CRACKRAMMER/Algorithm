#include "GenList.h"

int main(int argc, char *argv[]) {
    GenList gl;
    InitGenList(&gl);

    char *ga = "(1,2,3)";
    char *gb = "(1,(2,3))";
    char *gc = "(1,(2),3)";
    char *gd = "((1,2),3)";
    char *ge = "((1,2,3))";
    char *gf = "()";
    char *gg = "(1,(2,(3,4)),5)";

    CreateGenList(&gl, gc);
    PrintGenList(gl);
    int length = GenListLength(gl);
    printf("length = %d\n", length);
    int maxdepth = GenListDepth(gl);
    printf("maxdepth = %d\n", maxdepth);

    return 0;
}
