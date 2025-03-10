#include <stdio.h>
#include <malloc.h> //библиотека для взаимодействия с оперативной памятью

int main() { double *pointer1 = malloc(sizeof(double)), **pointer2 = malloc(sizeof(double)), ***pointer3 = malloc(sizeof(double)); pointer3 = &pointer2;pointer2 = &pointer1;printf("pointer3="); scanf("%lf", **pointer3); printf("pointer3=%lf\n", ***pointer3); free(**pointer3); free(*pointer3); free(pointer3); return 0; }