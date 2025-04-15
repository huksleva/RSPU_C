#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define SIZE 100

typedef struct StackElement {
    struct StackElement *next;
    struct StackElement *prev;
    char data;
} StackElement;

typedef struct Stack {
    StackElement *head;
} Stack;

void StackInit(Stack *stack) {
    if (stack == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    stack->head = NULL;
}

// Добавление элемента в стек
void push(Stack *stack, const char data) {
    if (stack == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    StackElement *stack_element = (StackElement *) malloc(sizeof(StackElement));
    stack_element->data = data;
    stack_element->prev = stack->head;

    if (stack->head != NULL) {
        stack_element->prev->next = stack_element;
    }

    stack->head = stack_element;
    stack_element->next = NULL;
}

// Извлечения элемента из стека
char pop(Stack *stack) {
    if (stack == NULL || stack->head == NULL) {
        printf("Stack is empty.\n");
        return 0; // В ASCII 0 обозначает NULL
    }

    const char data = stack->head->data;

    // Если стек состоит из одного элемента
    if (stack->head->prev == NULL) {
        stack->head = NULL;
        return data;
    }

    stack->head = stack->head->prev;
    stack->head->next->prev = NULL;
    stack->head->next = NULL;

    return data;
}

int main() {
    printf("Enter a math example in the form of postfix notation.\nOperands and operations must be written with a space (no more than 100 symbols).\n");
    printf("Example: 2 3 + 4 * 5 -\n>>");

    Stack *stack = (Stack*) malloc(sizeof(Stack));
    StackInit(stack);

    // Читаем по одному числу











    free(str);
    free(stack);

    return 0;
}
