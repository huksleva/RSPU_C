#include<stdio.h>
#include<math.h>

double MyFun(double x) {
    return (x * x + 3 * x - 5);
}

double fun(double x){
    return exp()
}

int main() {
    double a, b, n, h, sum;
    a = 5;
    b = 8;
    n = 10;
    h = (b - a) / n;
    sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += ((MyFun(a + h * i) - MyFun(a + h * (i - 1))) / 2 * (a + h * i - a + h * (i - 1)));
    }
    printf("MyFun: %lf", sum);

    sum = 0.0;




    return 0;
}
