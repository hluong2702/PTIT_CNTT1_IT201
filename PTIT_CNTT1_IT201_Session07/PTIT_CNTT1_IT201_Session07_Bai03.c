#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j +1] = arr[j];
            j --;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n, *arr;

    printf("Moi ban nhap so phan tu");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Khong hop le");
        return 0;
    }
    arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Before: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    insertionSort(arr, n);
    printf("After: ");
    for (int i = 0; i < n; i++) {
        printf(" %d ", arr[i]);
    }

    free(arr);
    return 0;
}
