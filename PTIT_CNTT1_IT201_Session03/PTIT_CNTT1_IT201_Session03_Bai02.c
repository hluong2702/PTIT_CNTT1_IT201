#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;

    do {
        printf("Moi ban nhap vao so luong phan tu ");
        scanf("%d", &n);
    }while( n > 1000);
    if (n < 0 || n == 0) {
        printf("So luong phan tu khong hop le");
    }
    arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Moi ban nhap phan tu %d ",i + 1);
        scanf("%d", &arr[i]);
    }

    int maxNum = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxNum) {
            maxNum = arr[i];
        }
    }
   printf("max = %d", maxNum);
    free(arr);
    return 0;
}
