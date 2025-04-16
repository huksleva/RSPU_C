#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct StackElement {
    struct StackElement *next;
    struct StackElement *prev;
    int data;
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
void push(Stack *stack, const int data) {
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
int pop(Stack *stack) {
    if (stack == NULL || stack->head == NULL) {
        printf("Stack is empty.\n");
        return 0; // В ASCII 0 обозначает NULL
    }

    const int data = stack->head->data;

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

// Проверка строки на корректность. Состоит ли строка только из десятичных цифр. Проверяем по ASCII
int isNumber(const char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}

int main() {
    printf("Enter a math example in the form of postfix notation.\nOperands and operations must be written with a space (no more than 100 symbols).\n");
    printf("Example: 2 3 + 4 * 5 -\n>>");

    // В стеке будут лежать только числа
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    StackInit(stack);


    // Читаем по одному оператору / операнду
    char *str = (char*) malloc(100 * sizeof(char));
    int left, right;
    do {
        scanf("%s[^ ]", str);
        if (*str == '+') {
            right = pop(stack);
            left = pop(stack);
            push(stack, left + right);
        } else if (*str == '*') {
            right = pop(stack);
            left = pop(stack);
            push(stack, left * right);
        } else if (*str == '-') {
            right = pop(stack);
            left = pop(stack);
            push(stack, left - right);
        } else if (*str == '/') {
            right = pop(stack);
            left = pop(stack);
            if (right == 0) {
                printf("ERROR: Division by zero.\n");
                free(str);
                free(stack);
                return 0;
            } // Проверка на деление на ноль
            push(stack, (int) (left / right));
        } else if (isNumber(str)) {
            push(stack, (int) strtol(str, NULL, 10));
        }
        else {
            printf("ERROR: Invalid input.\n");
            free(str);
            free(stack);
            return 0;
        }
    } while (getchar() != '\n');

    printf("Result: %d\n", pop(stack));
    if (stack->head != NULL) {
        printf("ERROR: Stack is not empty.\n");
    }

    free(str);
    free(stack);

    return 0;
}
