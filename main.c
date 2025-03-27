#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Book {
    unsigned short SIZE;
    char *title;
    char *author;
    unsigned short year;
};

void printbook(struct Book* book){
    printf("author: ");
    printf("%s", book->author);
    printf("\ntitle: ");
    printf("%s", book->title);
    printf("\nyear: %hd\n", book->year);
}

int main() {
    struct Book *arrBook = (struct Book*) malloc(3*sizeof(struct Book));
    for (int i = 0; i < 3; i++) {
        arrBook[i].SIZE = 50;
        arrBook[i].author = (char*) malloc(arrBook[i].SIZE*(sizeof(char)));
        arrBook[i].title = (char*) malloc(arrBook[i].SIZE*(sizeof(char)));
    }

    // Вводим данные в структуру
    for (int i = 0; i < 3; i++) {
        printf("\nstruct number %d:\n", i+1);
        printf("Enter autor (max 50 symbols):");
        scanf("%s", arrBook[i].author);
        printf("Enter title (max 50 symbols):");
        scanf("%s", arrBook[i].title);
        printf("Enter year:");
        scanf("%hd", &arrBook[i].year);
    }

    // Через функцию printbook() выводим структуры на экран
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf("Book number %d:\n", i+1);
        printbook(&arrBook[i]);
        printf("\n");
    }


    for (int i = 0; i < 3; i++){
        free(arrBook[i].title);
        free(arrBook[i].author);
    }
    free(arrBook);
    return 0;
}