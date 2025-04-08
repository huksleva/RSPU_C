#ifndef MAIN_C // если НЕ определена константа MAIN_C
#include <stdio.h>
#include "MatrixOperations.h"
#define MAIN_C // то определить ее
#endif


int main() {

    const int col1 = 3, row1 = 3;
    int** matrix1 = IntMatrix(col1, row1);
    IntMatRand(matrix1, col1, row1);
    printf("Matrix1:\n");
    MatPrint(matrix1, col1, row1);

    const int col2 = 3, row2 = 3;
    int** matrix2 = IntMatrix(col2, row2);
    IntMatRand(matrix2, col2, row2);
    printf("\nMatrix2:\n");
    MatPrint(matrix2, col2, row2);

    printf("\nMatrix1 * Matrix2:\n");
    int** matrix3 = MultiplyMatrix(matrix1, col1, row1, matrix2, col2, row2);
    MatPrint(matrix3, col1, row2);
    printf("\n");

    DelIntMatrix(matrix1, col1);
    DelIntMatrix(matrix2, col2);

    const int size = 10;
    int *arr = IntArray(size);
    IntArrRand(arr, size);
    printf("\n");
    ArrPrint(arr, size);

    return 0;
}