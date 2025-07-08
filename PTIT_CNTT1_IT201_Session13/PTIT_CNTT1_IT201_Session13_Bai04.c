#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int *arr;
    int top;
    int cap;
}Stack;

Stack* createStack(int cap) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->cap = cap;
    stack->top = -1;
    stack->arr = (int*)malloc(sizeof(int) * cap);
    return stack;
}

int isFull(Stack* stack) {
    if (stack->top == stack->cap - 1) {
        return 1;
    }
    return 0;
}

int push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow");
        return 0;
    }
    stack->top = stack->top + 1;
    stack->arr[stack->top] = value;
    return 1;
}

int isEmpty(Stack* stack) {
    if (stack->top == -1) {
        return 1;
    }
    return 0;
}

void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return;
    }
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]);
    }
}


int main() {
    Stack* stack = createStack(5);
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);
    printStack(stack);
    return 0;
}