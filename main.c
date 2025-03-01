#include<stdio.h>
#include<math.h>

int main() {
    const int SIZE = 10;
    int a[] = {5, 2, 8, 1, 3, 6, 4, 7, 9, 0};
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    int temp;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
