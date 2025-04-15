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

// Функция меняет местами два элемента стека
void swap(StackElement *left, StackElement *right) {
    // left - левый элемент
    // right - правый элемент
    // Если конец стека
    if (left == NULL) {
        return;
    }


    if (left->prev != NULL && right->next != NULL) {
        right->prev = left->prev;
        left->prev->next = right;

        right->next->prev = left;
        left->next = right->next;

        left->prev = right;
        right->next = left;
    }
    else if (left->prev != NULL && right->next == NULL) {
        right->prev = left->prev;
        left->prev->next = right;

        left->prev = right;
        right->next = left;

        left->next = NULL;
    }
    else if (left->prev == NULL && right->next != NULL) {
        left->prev = right;
        right->prev = NULL;

        left->next = right->next;
        right->next->prev = left;

        right->next = left;
    }
    else if (left->prev == NULL && right->next == NULL) {
        left->prev = right;
        right->next = left;

        left->next = NULL;
        right->prev = NULL;
    }
}

void siftStackElement(Stack *stack) {
    if (stack == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    StackElement *left = stack->head->prev;
    StackElement *right = stack->head;

    while (left != NULL && left->data < right->data) {
        swap(left, right); // Меняет местами два элемента

        // Если менялась голова, то возвращаем её на место
        if (stack->head == right) {
            stack->head = left;
        }

        // Обновляем указатели. Меняем левый и правый местами, а также сдвигаем их на один элемент влево
        StackElement *temp = left;
        left = right;
        right = temp;

        left = left->prev;
        right = right->prev;
    }
}

int main() {
    // В Windows длина пути к файлу не превышает 260 символов, поэтому _MAX_PATH = 260
    printf("Specify the path to the file (no more than %d characters).\n>", _MAX_PATH);
    char *path = (char*) malloc(_MAX_PATH * sizeof(char));


    // Считываем не более 260 символов и до того момента, пока не встретим символ '\n'
    scanf("%260[^\n]", path);



    // Открываем файл
    FILE *f = fopen(path, "r");

    if (f == NULL) {
        printf("The file does not exist.\n");
        fclose(f);
        free(path);
        return 0;
    }

    // Создаём связный список. Им будет стек.
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    StackInit(stack);

    int num;

    // Пока не конец файла
    while (!feof(f)) {
        fscanf(f, "%d", &num); // Считываем число
        push(stack, num); // Добавляем его в стек
        siftStackElement(stack); // Просеваем число в стеке
    }

    // Выводим стек
    while (stack->head != NULL) {
        printf("%d ", pop(stack));
    }
    printf("\n");

    fclose(f);
    free(path);
    free(stack);

    return 0;
}
