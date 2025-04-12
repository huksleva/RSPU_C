#include <stdio.h>
#include <stdlib.h>

// Функция вычисления факториала
unsigned long long factorial(const unsigned long long n) {
    if (n == 0) {
        return 1;
    }
    unsigned long long result = 1;
    for (unsigned long long i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Функция вычисления биноминального коэффициента
unsigned long long C(const unsigned short n, const unsigned short k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

// Печать пробелов для красивого треугольника
void PreSpaces(const unsigned short count) {
    for (unsigned short i = 0; i < count; i++) {
        printf(" ");
    }
}

int main() {
    printf("Enter count of strings of the Pascal triangle:");
    unsigned short N = 0; // от 0 до 65535
    scanf("%hd", &N);
    printf("Pascal triangle:\n");

    // Динамически выделяем память под массив, в котором будем хранить треугольник Паскаля
    unsigned long long** triangle = (unsigned long long**) malloc(N * sizeof(unsigned long long*));
    for (unsigned short i = 0; i < N; i++) {
        triangle[i] = (unsigned long long*) malloc((i + 1) * sizeof(unsigned long long));

        // Используем бином Ньютона, чтобы построить треугольник Паскаля
        for (unsigned short k = 0; k <= i; k++) {
            triangle[i][k] = C(i, k);
        }
    }

    // Печатаем треугольник
    for (unsigned short i = 0; i < N; i++) {
        PreSpaces(N - i);
        for (unsigned short k = 0; k <= i; k++) {
            printf("%llu ", triangle[i][k]);
        }
        printf("\n");
    }

    // Освобождаем память
    for (unsigned short i = 0; i < N; i++) {
        free(triangle[i]);
    }
    free(triangle);

    return 0;
}
