#include "SeqList.h"

int main(int argc, char *argv[]) {
    SeqList list;
    InitSeqList(&list);
    ElemType data;
    int pos;

    int select = 1;
    while(select) {
        printf("***********************************\n");
        printf("* [1]  push_back  [2]  push_front *\n");
        printf("* [3]  show_list  [4]  pop_back   *\n");
        printf("* [5]  pop_front  [6]  insert_pos *\n");
        printf("* [7]  find       [8]  lenght     *\n");
        printf("* [9]  delete_pos [10] delete_val *\n");
        printf("* [11] sort       [12] resver     *\n");
        printf("* [13] clear                      *\n");
        printf("* [0]  quit_system                *\n");
        printf("***********************************\n");
        printf("请选择:>");
        scanf("%d", &select);

        if(select == 0) {
            break;
        }

        switch(select) {
        case 1:
            printf("请输入要插入的数据（-1结束）：");
            while(scanf("%d", &data), data != -1)
                push_back(&list, data);
            break;
        case 2:
            printf("请输入要插入的数据（-1结束）：");
            while(scanf("%d", &data), data != -1)
                push_front(&list, data);
            break;
        case 3:
            show_list(&list);
            break;
        case 4:
            pop_back(&list);
            break;
        case 5:
            pop_front(&list);
            break;
        case 6:
            printf("请输入要插入的数据：");
            scanf("%d", &data);
            printf("请输入要插入的位置：");
            scanf("%d", &pos);
            insert_pos(&list, pos, data);
            break;
        case 7:
            printf("请输入要查找的数据：");
            scanf("%d", &data);
            pos = find(&list, data);
            if(pos == -1) {
                printf("查找的数据%d在顺序表中不存在。\n", data);
            } else {
                printf("查找的数据%d在顺序表中的%d下标位置。\n", data, pos);
            }
            break;
        case 8:
            printf("顺序表的长度为：%d\n", lenght(&list));
            break;
        case 9:
            printf("请输入要删除的位置：");
            scanf("%d", &pos);
            delete_pos(&list, pos);
            break;
        case 10:
            printf("请输入要删除的数据：");
            scanf("%d", &data);
            delete_val(&list, data);
            break;
        case 11:
            sort(&list);
            break;
        case 12:
            resver(&list);
            break;
        case 13:
            clear(&list);
            break;
        default:
            printf("输入的选择错误，请重新输入。\n");
            break;
        }
    }

    destroy(&list);
}