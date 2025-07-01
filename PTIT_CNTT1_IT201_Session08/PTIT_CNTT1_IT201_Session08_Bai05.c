#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j --;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n, *arr;

    printf("Moi ban nhap vao so luong phan tu ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Khong hop le");
        return 0;
    }
    arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d ",i+1);
        scanf("%d", &arr[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    insertionSort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}
// 0(n^2)