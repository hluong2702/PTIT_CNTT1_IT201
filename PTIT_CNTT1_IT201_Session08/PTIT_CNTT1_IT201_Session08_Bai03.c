#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                count++;
            }
        }
        if (count == 0) {
            break;
        }
    }
}

int main() {
    int n ,*arr;

    printf("Moi ban nhap vao soluong phan tu");
    scanf("%d",&n);

    if (n <= 0 || n > 100) {
        printf("Khong hop le");
        return 0;
    }

    arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d ",i+1);
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}

// 0(n^2)
