#include <stdio.h>
#include <math.h>
#include <complex.h>

typedef struct Complex {
    double real;
    double imag;
}Complex;

int factorial(int n) {
    if (n == 0) {
        return 1;
    }

    int sum = 1;
    for (int i = 1; i <= n; i++) {
        sum *= i;
    }
    return sum;
}

Complex powComplex(Complex z, int n) {

    // Используем формулу Муавра. Для этого найдём угол поворота (Fi) фи и расстояние (r).
    double r = sqrt(z.real * z.real + z.imag * z.imag); // Расстояние
    double Fi = atan(z.imag / z.real); // Угол поворота

    double r_n = pow(r, n); // Расстояние в степени n. Вычисляем сейчас, чтобы потом не вычислять два раза.
    z.real = r_n * cos(n*Fi); // Вещественная часть
    z.imag = r_n * sin(n*Fi); // Мнимая часть

    return z;
}

int main() {
    printf("z = a + bi\nEnter the Real part:");
    Complex z;
    scanf("%lf", &z.real);
    printf("Enter the Imaginary part:");
    scanf("%lf", &z.imag);
    printf("z = %lf + %lfi\n\n", z.real, z.imag);










    
    Complex c = {0, 0};
    Complex c_stakan;
    double fraction; // Дробная часть выражения
    for (int i = 0; i <= 20; i++) {
        fraction = 1.0 / factorial(i);
        c_stakan = powComplex(z, i);
        c.real += c_stakan.real * fraction;
        c.imag += c_stakan.imag * fraction;
    }

    printf("e^(i*Fi) = %lf + %lfi\n", c.real, c.imag);

    double complex x = 1 + 2*I;

    printf("\n\nLOOOOL: %lf", 8);




    return 0;
}
