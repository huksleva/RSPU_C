#include <stdio.h>
#include <malloc.h>

typedef struct StackElement {
    struct StackElement *prev;
    char data;
} StackElement;

typedef struct Stack {
    StackElement *head;
} Stack;

void StackInit(Stack *stack) {
    stack->head = NULL;
}

// Добавление элемента в стек
void push(Stack *stack, const char data) {
    StackElement *element = (StackElement *) malloc(sizeof(StackElement));
    element->data = data;
    element->prev = stack->head;
    stack->head = element;
}

// Извлечения элемента из стека
char pop(Stack *stack) {
    if (stack->head == NULL) {
        printf("Stack is empty.\n");
        return 0; // В ASCII 0 обозначает NULL
    }
    const char data = stack->head->data;
    StackElement *st = stack->head;
    stack->head = stack->head->prev;
    free(st);
    return data;
}

int main() {
    printf("Enter the string with round, square and figure brackets:");
    Stack stack;
    StackInit(&stack);
    push(&stack, (char) getchar());

    while (stack.head->data != '\n') {
        push(&stack, (char) getchar());
    }

    int round_brackets = 0, figure_brackets = 0, square_brackets = 0;
    char ch = pop(&stack); // Здесь ch всегда = '/n' (символ переноса строки, он же Enter)

    while ((stack.head != NULL) && (ch != 0)) {
        ch = pop(&stack);

        // Проверка на круглые скобки
        if (ch == '(') {
            round_brackets++;
        } else if (ch == ')') {
            round_brackets--;
        }

        // Проверка на фигурные скобки
        if (ch == '{') {
            figure_brackets++;
        } else if (ch == '}') {
            figure_brackets--;
        }

        // Проверка на квадратные скобки
        if (ch == '[') {
            square_brackets++;
        } else if (ch == ']') {
            square_brackets--;
        }
    }

    if ((round_brackets == 0) && (figure_brackets == 0) && (square_brackets == 0)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}

