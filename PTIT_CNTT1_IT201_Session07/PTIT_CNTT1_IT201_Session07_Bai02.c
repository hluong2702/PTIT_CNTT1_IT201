#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        }
    }
}

int main() {
    int n,*arr;

    printf("Moi ban nhap so luong phan tu ");
    scanf("%d",&n);

    if (n < 0 || n > 100) {
        printf("Khong hop le");
        return 0;
    }
    arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu %d : ", i+1);
        scanf("%d",&arr[i]);
    }
    printf("Before");
    for (int i = 0; i < n; i++) {
        printf(" %d ", arr[i]);
    }
    printf("\n");
    selectionSort(arr, n);
    printf("After");
    for (int i = 0; i < n; i++) {
        printf(" %d ", arr[i]);
    }

    free(arr);
    return 0;

}
