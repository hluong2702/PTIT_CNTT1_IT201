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

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return 0;
    }
    stack->top = stack->top - 1;
    return stack->arr[stack->top--];
}

void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return;
    }
    for (int i = stack ->top; i >= 0 ; i--) {
        printf("%d ", stack->arr[i]);
    }
}

int main() {
    int value;

    Stack* stack = createStack(5);
    for (int i = 0; i < 5; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        push(stack, value);
    }
    printStack(stack);
    printf("\n");
    return 0;

}