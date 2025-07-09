#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
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
        printf("Stack overflow\n");
        return 0;
    }
    Node* current = stack->head;
    int data = current->data;
    stack->head = current->next;
    free(current);
    return data;
}

void printStack(Stack* stack) {
     if (isEmpty(stack)) {
         printf("Stack empty\n");
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

    int n;
    Stack* stack = createStack(5);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    printStack(stack);

    printf("Moi ban nhap vao so nguyen duong bat ki ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Khong hop le");
        return 0;
    }
    push(stack, n);
    printStack(stack);
}