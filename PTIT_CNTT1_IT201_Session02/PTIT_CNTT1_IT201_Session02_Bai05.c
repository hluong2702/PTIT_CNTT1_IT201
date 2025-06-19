#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;
    int pos;

    do {
        printf("Nhap so luong phan tu ");
        scanf("%d", &n);
    }while(n <= 0 || n >100);
    arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu %d",i +1);
        scanf("%d", &arr[i]);
    }

    printf("Mang goc la ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    do {
    printf("Nhap vi tri can xoa");
    scanf("%d", &pos);
    }while(pos < 0 || pos > n);

    for (int i = pos - 1 ; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    printf("Mang sau khi xoa la: ");
    for (int i = 0; i < n -1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
