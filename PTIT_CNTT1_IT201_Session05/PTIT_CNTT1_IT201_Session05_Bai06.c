#include <stdio.h>
#include <stdlib.h>

int sumRecursive(int arr[] , int size, int index) {
    if (index >= size) {
        return 0;
    }
    return arr[index] + sumRecursive(arr, size, index + 1);
}

int main() {
    int n , *arr;

    printf("Nhap so phan tu: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Khong hop le");
        return 0;
    }
    arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d",i+1);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int sum = sumRecursive(arr, n, 0);
    printf("%d", sum);
    return 0;

}
