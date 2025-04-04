#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

#define SIZE 20

int main() {
    char str[SIZE] = "Leonid Tots 2005";

    for (int i = 0; i < strlen(str); i++) {
        printf("Symbol '%c':\n", str[i]);
        printf("   isalnum: %d\n", isalnum(str[i]));
        printf("   isalpha: %d\n", isalpha(str[i]));
        printf("   islower: %d\n", islower(str[i]));
        printf("   isupper: %d\n", isupper(str[i]));
        printf("   isdigit: %d\n", isdigit(str[i]));
        printf("   isxdigit: %d\n", isxdigit(str[i]));
        printf("   iscntrl: %d\n", iscntrl(str[i]));
        printf("   isgraph: %d\n", isgraph(str[i]));
        printf("   isspace: %d\n", isspace(str[i]));
        printf("   isblank: %d\n", isblank(str[i]));
        printf("   isprint: %d\n", isprint(str[i]));
        printf("   ispunct: %d\n", ispunct(str[i]));
    }

    return 0;
}