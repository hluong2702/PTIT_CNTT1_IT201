#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n) {
    if (n<=1) {
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

void printfFibonacci(int n) {
    int *list = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        list[i] = fibonacci(i);
    }
    for (int i = n -1 ; i >= 0; i--) {
        printf("%d ", list[i]);
    }
    free(list);
}

int main() {
    int n;

    printf("Moi ban nhap so nguyen n ");
    scanf("%d", &n);

    if (n <=0 || n > 10 ) {
        printf("Khong hop le");
        return 0;
    }
    printfFibonacci(n);
    return 0;

}