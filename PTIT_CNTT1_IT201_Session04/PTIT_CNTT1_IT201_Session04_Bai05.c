#include <stdio.h>
#include <stdlib.h>

int binarySearch(int n, int x, int *arr) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < x) {
            left = mid + 1;
        }else {
            right = mid;
        }
    }
    if (arr[left] == x) {
        return left;
    }
    return -1;
}

int main() {
    int *arr ,n,x;

    printf("Moi ban nhap vao so luong phan tu");
    scanf("%d",&n);

    if (n <= 0) {
        printf("So luong phan tu khong hop le");
        return 0;
    }
    arr = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d ",i+1);
        scanf("%d",&arr[i]);
    }

    int temp;
    for (int i = 0; i < n -1; i++) {
        for (int j = 0; j < n - i -1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }

    printf("Moi ban nhap vao mot gia tri bat ki");
    scanf("%d",&x);

    int result = binarySearch(n,x,arr);

    if (result == -1) {
        printf("Phan tu khong co trong mang");
    }else {
        printf("Phan tu co trong mang");
    }

    free(arr);
    return 0;
}
