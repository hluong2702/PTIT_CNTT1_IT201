#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow");
        return 0;
    }
    return stack->arr[stack->top--];
}

int isPalindrome(char* str) {
    int len = strlen(str);
    Stack* stack = createStack(len);
    for (int i = 0; i < len ; i++) {
        push(stack, str[i]);
    }
    for (int i = 0; i < len; i++) {
        char popped = pop(stack);
        if (popped != str[i]) {
            free(stack->arr);
            free(stack);
            return 0;
        }

    }
    free(stack->arr);
    free(stack);
    return 1;
}

int main() {
    char str[100];
    printf("Moi ban nhap vao chuoi");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';

    if (isPalindrome(str)) {
        printf("true");
    }else {
        printf("false");
    }
    return 0;

}