#include "StaticList.h"

int main(int argc, char *argv[]) {
    StaticList SL;
    InitStaticList(SL);

    for(int i = 0; i < 5; i++) {
        Insert(SL, 'A' + i);
    }
    ShowStaticList(SL);
    Delete(SL);
    ShowStaticList(SL);
}