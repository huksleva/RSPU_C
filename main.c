#include <stdio.h>
#include <stdlib.h>

int main() {
    const int numOfStrings = 5;
    char *strings = (char*) malloc(numOfStrings * sizeof(char*));

    for (int i = 0; i < numOfStrings; i++) {
        free(&strings[i]);
    }
    free(strings);

    return 0;
}