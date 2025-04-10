#ifndef RSPU_C_ALLOCATEMEMORY_C // если НЕ определена константа RSPU_C_ALLOCATEMEMORY_H
#define RSPU_C_ALLOCATEMEMORY_C // определяем константу SOMECODE_H
#include <malloc.h>
#include <stdio.h>

int* IntArray(int size) {
    return (int*) malloc(size * sizeof(int));
}

int** IntMatrix(int col, int row) {
    int** mat = (int**) malloc(col * sizeof(int*));
    for (int i = 0; i < col; i++) {
        mat[i] = (int*) malloc(row * sizeof(int));
    }
    return mat;
}

void DelIntArray(int* arr) {
    free(arr);
    printf("Array deleted.\n");
}

void DelIntMatrix(int** matrix, int col) {
    for (int i = 0; i < col; i++) {
        free(matrix[i]);
    }
    free(matrix);
    printf("Matrix removed.\n");
}

#endif //RSPU_C_ALLOCATEMEMORY_C
