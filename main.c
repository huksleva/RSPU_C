#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Vec{
    int x;
    int y;
    int z;
    char* name;
} Vector;

int scalarVectorMultiplication(Vector vec1, Vector vec2){
    return ((vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z));
}

Vector* VectorMultiplication(Vector vec1, Vector vec2){
    //после завершения работы функции переменная result удалится из оперативки
    Vector* result = (Vector*) malloc(sizeof(Vector));
    result->x = (vec1.y* vec2.z) - (vec1.z * vec2.y);
    result->y = -((vec1.x * vec2.z) + (vec1.z * vec2.x));
    result->x = (vec1.x * vec2.y) + (vec1.y * vec2.x);
    return result; //перед удалением result будет возвращен указатель
}

double ModuleVector(Vector vec1){
    return sqrt((vec1.x * vec1.x) + (vec1.y * vec1.y) + (vec1.z * vec1.z));
}

void PrintVector(Vector vec1){
    printf("Vector %s: %d %d %d\n", vec1.name, vec1.x, vec1.y, vec1.z);
}

int main() {
    Vector v = {1,2,3, "MyName"};
    PrintVector(v);
    printf("ModuleVector: %f\n", ModuleVector(v));
    printf("ScalarVectorMultiplication: %d\n", scalarVectorMultiplication(v, v));

    Vector *result = VectorMultiplication(v, v);
    printf("VectorMultiplication: %d %d %d\n", result->x, result->y, result->z);
    free(result);

    return 0;
}