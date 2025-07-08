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
        return -1;
    }
    return stack->arr[stack->top--];
}

void initStack(Stack* stack) {
    stack->top = -1;
}
void reverseStack(int arr[], int n ) {
    Stack* stack = createStack(n);
    initStack(stack);
    for (int i = 0; i < n; i++) {
        push(stack, arr[i]);
    }
    for (int i = 0; i < n; i++) {
        arr[i] = pop(stack);
    }
}

void printStack(int arr[],int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Moi ban nhap vao so phan tu cua mang");
    scanf("%d",&n);

    if (n < 0 || n > 100) {
        printf("Khong hop le");
        return 0;
    }
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu %d ",i + 1);
        scanf("%d",&arr[i]);
    }
    printStack(arr,n);
    reverseStack(arr,n);
    printStack(arr,n);
    return 0;
}