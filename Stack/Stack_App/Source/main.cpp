#include "LinkStack.h"

void Convert_8(int value) {
    LinkStack st;
    InitStack(&st);
    ElemType data;

    while(value) {
        Push(&st, value % 8);
        value /= 8;
    }
    while(Pop(&st, &data) != -1) {
        printf("%d", data);
    }
    printf("\n");
    
}

bool Cheak(char *str) {
    LinkStack st;
    InitStack(&st);
    ElemType data;

    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == '(' 
        || str[i] == '[' 
        || str[i] == '{' ) {
            Push(&st, str[i]);
        } else {
            switch(str[i]) {
            case ')':
                Pop(&st, &data);
                if(data != '(') return false;
                break;
            case ']':
                Pop(&st, &data);
                if(data != '[') return false;
                break;
            case '}':
                Pop(&st, &data);
                if(data != '{') return false;
                break;
            }
        }
    }

    if(Length(&st) == 0) return true;
    else return false;
}

void LineEdit() {
    LinkStack st;
    InitStack(&st);
    ElemType data;

    char ch;
    do {
        ch = getchar();
        switch(ch) {
        case '#':
            Pop(&st, &data);
            break;
        case '@':
            Clear(&st);
            break;
        case '$':
            break;
        case '\n':
            Print(&st);
            Clear(&st);
            break;
        default:
            Push(&st, ch);
            break;
        }

    } while(ch != '$');
}

int main(int argc, char *argv[]) {
    // 十进制转八进制
    // int value = 47183;
    // Convert_8(value);

    // 括号匹配
    // char *str = "[([][{}])]";
    // if(Cheak(str)) {
    //     printf("OK!\n");
    // } else {
    //     printf("Error!\n");
    // }

    // 行编辑
    LineEdit();
}