#include <stdio.h>
#include <stdlib.h>


typedef struct MyStruct{
    union ASCII{
        unsigned short num;
        char sym;
    }ASCII;

    enum Indicator{
        SYMBOL,
        NUMBER
    }Indicator;

}MyStruct;

void printMyStruct(MyStruct *s, int size) {
    for (int i = 0; i < size; i++) {
        if (s[i].Indicator == SYMBOL) {
            printf("Struct %d: SYMBOL = %c\n", i+1, s[i].ASCII.sym);
        } else if (s[i].Indicator == NUMBER) {
            printf("Struct %d: NUMBER = %hu\n", i+1, s[i].ASCII.num);
        }
    }
}

int main() {
    MyStruct *StructArr = (MyStruct *) malloc(sizeof(MyStruct) * 3);

    StructArr[0].Indicator = NUMBER;
    StructArr[0].ASCII.num = 77;

    StructArr[1].Indicator = SYMBOL;
    StructArr[1].ASCII.sym = 'a';

    StructArr[2].Indicator = NUMBER;
    StructArr[2].ASCII.num = 97;

    printMyStruct(StructArr, 3);

    free(StructArr);

    return 0;
}