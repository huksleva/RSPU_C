#ifndef RSPU_C_ALLOCATEMEMORY_H // если НЕ определена константа RSPU_C_ALLOCATEMEMORY_H
#define RSPU_C_ALLOCATEMEMORY_H // определяем константу SOMECODE_H
#include <malloc.h>
#include <stdio.h>

int* IntArray(int);

int** IntMatrix(int, int);

void DelIntArray(int*);

void DelIntMatrix(int**, int);

#endif //RSPU_C_ALLOCATEMEMORY_H
