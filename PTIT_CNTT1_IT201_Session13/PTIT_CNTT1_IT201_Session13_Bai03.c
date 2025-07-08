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
        printf("Stack overflow\n");
        return -1;
    }
    stack->top = stack->top + 1;
    stack->arr[stack->top] = value;
    return 0;
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
        return -1;
    }
    return stack->arr[stack->top--];
}
int main() {
    Stack* stack = createStack(5);
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);

    if (isEmpty(stack)) {
        printf("No element in stack\n");
        return 0;
    }else {
        int popped = pop(stack);
        printf("Popped element is %d\n", popped);
    }
    return 0;
}