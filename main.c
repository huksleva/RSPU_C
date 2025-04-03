#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
    Node *tail;
} List;

void List_init(List *list) {
    list->head = NULL;
    list->tail = NULL;
}

void Node_init(Node *node){
    node->next = NULL;
    node->prev = NULL;
}

// Операция добавления элемента списка. Работает за O(1)
void Add(int Data, Node *head) {

    head->next = (Node *) malloc(sizeof(Node));
    head->next->prev = head;
    head->next->data = Data;

}

void printFromHead(List *list) {
    Node *node = list->head;
    while (node->prev != NULL) {
        printf("%d ", node->data);
        node = node->prev;
    }
    printf("\n");
}

void printFromTail(List *list) {
    Node *node = list->tail;
    while (node->next != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    List list;
    List_init(&list);
    Node node;
    Node_init(&node);



    insert(1, &node, &list);
    insert(2, &node, &list);
    insert(3, &node, &list);
    insert(4, &node, &list);
    insert(5, &node, &list);

    printFromHead(&list);
    printFromTail(&list);




    return 0;
}