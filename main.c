#include <stdio.h>
#include <malloc.h>

int main() {

    //Размер типа double умножаем на кол-во элементов массива. Явно задаём тип возвращаемого значения функции - double*
    double *arr = (double*) malloc(10*sizeof(double));

    for (double *i = arr; i < sizeof(arr)/sizeof(double*); i++){
        printf("Enter %d element (double):" );
        scanf("%lf", &arr[i]);
    }

    free(arr);
    return 0;
}
//1.1 1.2 1.3 1.4 1.5 1.6 1.7 1.8 1.9 2.0