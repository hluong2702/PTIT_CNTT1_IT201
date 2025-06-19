#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;
    int pos, newValue;


    do {
        printf("Nhap so luong phan tu ");
        scanf("%d", &n);
    }while(n <=0 || n > 100);
    arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Mang goc la");
    for (int i = 0; i < n; i++) {
        printf(" %d ", arr[i]);
    }
    printf("\n");

    do {
        printf("Nhap vi tri can sua ");
        scanf("%d", &pos);
    }while(pos < 0 || pos > n);

    printf("Nhap gia tri moi cua vi tri do");
    scanf("%d", &newValue);
    arr[pos] = newValue;

    printf("Mang cap nhat ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
