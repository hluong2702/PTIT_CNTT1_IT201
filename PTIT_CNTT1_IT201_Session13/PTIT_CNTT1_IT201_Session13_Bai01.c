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

int push(Stack* stack, int val) {
    if (isFull(stack)) {
        printf("Stack overflow");
        return 0;
    }
    stack->top = stack->top + 1;
    stack->arr[stack->top] = val;
    return 1;
}

int isEmpty(Stack* stack) {
    if (stack->top == -1) {
        return 1;
    }
    return 0;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow");
        return 0;
    }
    stack->top = stack->top - 1;
    return stack->arr[stack->top--];
}

int main() {
    Stack* stack = createStack(5);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    return 0;
}