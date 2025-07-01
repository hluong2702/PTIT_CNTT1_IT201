#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < key) {
            left = mid + 1;
        }else {
            right = mid;
        }
    }
    if (arr[left] == key) {
        return left;
    }
    return -1;
}

int main() {
    int n, *arr , key;

    printf("Moi ban nhap vao so luong phan tu");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Khong hop le");
        return 0;
    }

    arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu %d", i + 1);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Nhap phan tu muon tim kiem");
    scanf("%d", &key);
    int result = binarySearch(arr, n, key);

    if (result == -1) {
        printf("Khong ton tai phan tu");
    }else {
        printf("Vi tri thu %d ",result);
    }
    free(arr);
    return 0;
}

//0(1)
