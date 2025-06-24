#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;

    do {
        printf("Nhap so luong phan tu n : ");
        scanf("%d", &n);
    } while (n <= 0 || n >= 1000);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Nhap %d phan tu cua mang:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Nhap so luong phan tu them vao mang (m): ");
    scanf("%d", &m);

    int *newArr = (int *)realloc(arr, (n + m) * sizeof(int));
    arr = newArr;

    printf("Nhap %d phan tu them vao mang:\n", m);
    for (int i = n; i < n + m; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n + m; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}