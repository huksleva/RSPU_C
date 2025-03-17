#include <stdio.h>

int sum(int a, int b){
    return a + b;
}

struct mathStruct{
    void *fun;
}mathStruct;

int main() {
    mathStruct.fun = &sum;

    //printf("%d\n", mathStruct.fun(1, 6));



    return 0;
}