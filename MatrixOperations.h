#ifndef RSPU_C_MATRIXOPERATIONS_H
#define RSPU_C_MATRIXOPERATIONS_H

#include "AllocateMemory.h"

int** MultiplyMatrix(int** matrix1, int col1, int row1, int** matrix2, int col2, int row2) {
    if (row1 != col2) {
        printf("Cannot multiply matrix with sizes %d*%d and %d*%d\n", row1, col1, row2, col2);
        return NULL;
    }
    
    int** result = (int**)malloc(col1 * sizeof(int*));
    for (int i = 0; i < col1; i++) {
        result[i] = (int*)malloc(row2 * sizeof(int));
    }
    
    for (int i = 0; i < col1; i++) {
        for (int j = 0; j < row2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < row1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    
    return result;
}

void IntMatRand(int** matrix, int col, int row) {
    for (int i = 0; i < col; i++) {
        for (int g = 0; g < row; g++) {
            matrix[i][g] = rand() % (20 + 1) - 10;
        }
    }
}

void IntArrRand(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (20 + 1) - 10;
    }
}

void MatPrint(int **matrix, int col, int row) {
    for (int i = 0; i < col; i++) {
        for (int g = 0; g < row; g++) {
            printf("%d ", matrix[i][g]);
        }
        printf("\n");
    }
}

void ArrPrint(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

#endif //RSPU_C_MATRIXOPERATIONS_H
