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

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->head = NULL;
    return stack;
}

void push(Stack* stack, int value) {
    Node* node = createNode(value);
    node->next = stack->head;
    stack->head = node;
}

int isEmpty(Stack* stack) {
    return stack->head == NULL;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    Node* current = stack->head;
    int data = current->data;
    stack->head = current->next;
    free(current);
    return data;
}

int firstData(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack overflow\n");
        return -1;
    }
    return stack->head->data;
}

void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack overflow\n");
        return;
    }
    Node* current = stack->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Stack* stack = createStack();
    printf("%d\n", firstData(stack));
    push(stack,5);
    push(stack,4);
    push(stack,3);
    push(stack,2);
    push(stack,1);
    printStack(stack);
    printf("Phan tu dau tien cua ngan xep la %d\n", firstData(stack));
    return 0;

}