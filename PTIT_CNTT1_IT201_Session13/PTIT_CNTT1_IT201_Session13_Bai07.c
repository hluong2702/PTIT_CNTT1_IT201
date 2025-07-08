#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    char *arr;
    int top;
    int cap;
}Stack;

Stack* createStack(int cap) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->cap = cap ;
    stack->top = -1;
    stack->arr = (char*)malloc(stack->cap * sizeof(int));
    return stack;
}

int isFull(Stack* stack) {
    if (stack->top == stack->cap - 1) {
        return 1;
    }
    return 0;
}

int push(Stack* stack, char value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return 0;
    }
    stack->arr[++stack->top] = value;
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
    return stack->arr[stack->top--];
}

int validMark(char open, char close) {
    return (open == '(' && close == ')')||(open == '[' && close == ']')||(open == '{' && close == '}');
}

int isValidityOfParentheses(char* str) {
    int len = strlen(str);
    Stack* stack = createStack(len);
    for (int i = 0; i < len; i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            push(stack, str[i]);
        }else if ( str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (stack->top == -1) {
                free(stack);
                return 0;
            }
            char popped = pop(stack);
            if (!validMark(popped, str[i])) {
                free(stack);
                return 0;
            }
        }
    }
    free(stack);
    return 1;
}

int main() {
    char str[100];
    printf("Moi ban nhap co ca dau ngoac nhe");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';
    if (isValidityOfParentheses(str)) {
        printf("True\n");
    }else {
        printf("False\n");
    }
    return 0;
}