#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;
    do {
        printf("Nhap so luong phan tu ");
        scanf("%d", &n);
    } while (n <= 0 || n > 100);

    arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Phan tu lon nhat trong mang la %d\n", max);

    free(arr);
    return 0;
}