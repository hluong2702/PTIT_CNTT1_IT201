#include <stdio.h>
#include <stdlib.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, *arr , key;

    printf("Moi ban nhap so luong phan tu ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("So luong phan tu khong hop le");
        return 0;
    }
    arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Nhap phan thu thu %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Moi ban nhap vao so can tim ");
    scanf("%d", &key);

    int result = linearSearch(arr, n, key);
    if (result == -1) {
        printf("Khong ton tai phan tu");
    }else {
        printf("Vi tri thu %d ",result);
    }
    free(arr);
    return 0;
}
// 0(1)
