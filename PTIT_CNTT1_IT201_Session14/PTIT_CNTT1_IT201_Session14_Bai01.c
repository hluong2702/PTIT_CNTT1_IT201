#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    return node;
}

typedef struct Stack {
    Node* head;
}Stack;

Stack* createStack(int cap) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->head = NULL;
    return stack;
}

void push(Stack* stack, int value) {
    Node* newNode = createNode(value);
    newNode->next = stack->head;
    stack->head = newNode;
}

int isEmpty(Stack* stack) {
    return stack->head == NULL;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack overflow");
        return 0;
    }
    Node* current = stack->head;
    int data = current->data;
    stack->head = current->next;
    free(current);
    return data;
}

int main() {
    Stack* stack = createStack(10);
    push(stack, 10);
    return 0;
}