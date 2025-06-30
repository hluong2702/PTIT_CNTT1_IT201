#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n -1; i++) {
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
}

int main() {
    int n , *arr;

    printf("Moi ban nhap vao so luong phan tu");
    scanf("%d", &n);

    if (n <=0 || n > 100) {
        printf("Khong hop le");
        return 0;
    }
    arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Before");
    for (int i = 0; i < n; i++) {
        printf(" %d ", arr[i]);
    }
    printf("\n");
    bubbleSort(arr, n);
    printf("After");
    for (int i = 0; i < n; i++) {
        printf(" %d ", arr[i]);
    }

    free(arr);
    return 0;
}
