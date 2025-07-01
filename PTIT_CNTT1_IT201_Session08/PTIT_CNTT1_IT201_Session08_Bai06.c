#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left , int mid, int right) {
    int sizeLeft = mid - left + 1;
    int sizeRight = right - mid;

    int *arrLeft = (int *) malloc(sizeLeft * sizeof(int));
    int *arrRight = (int *) malloc(sizeRight * sizeof(int));
    for (int i = 0; i < sizeLeft; i++) {
        arrLeft[i] = arr[left + i];
    }
    for (int i = 0; i < sizeRight; i++) {
        arrRight[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = left;
    while (i < sizeLeft && j < sizeRight) {
        if (arrLeft[i] <= arrRight[j]) {
            arr[k ++] = arrLeft[i ++];
        }else {
            arr[k ++] = arrRight[j ++];
        }
    }
    while (i < sizeLeft) {
        arr[k ++] = arrLeft[i ++];
    }
    while (j < sizeRight) {
        arr[k ++] = arrRight[j ++];
    }
    free(arrLeft);
    free(arrRight);

}
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n, *arr;

    printf("Moi ban nhap vao so luong phan tu ");
    scanf("%d", &n);

    if (n <=0 || n > 100) {
        printf("Khong hop le");
        return 0;
    }
    arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d ",i+1);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;

}
// 0(n log n)
