#include <stdio.h>
#include <stdlib.h>
#include <math.h>

enum Seasons {
    WINTER, SPRING, SUMMER, AUTUMN
};

int main() {
    printf("Enter num of month (1-12):");
    int m;
    scanf("%d", &m);

    if ((m == 12) || (m == 1) || (m == 2)) {
        printf("WINTER\n");
    }
    else if ((m == 3) || (m == 4) || (m == 5)){
        printf("SPRING\n");
    }
    else if ((m == 6) || (m == 7) || (m == 8)) {
        printf("SUMMER\n");
    }
    else if ((m == 9) || (m == 10) || (m == 11)) {
        printf("AUTUMN\n");
    }
    else {
        printf("ERROR\n");
    }

    return 0;
}