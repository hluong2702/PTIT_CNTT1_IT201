#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;
    int number;
    int count = 0;

    do {
        printf("Nhap so luong phan tu ");
        scanf("%d", &n);
    }while (n <= 0 || n > 100);
    arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Nhap so can dem ");
    scanf("%d", &number);

    for (int i = 0; i < n; i++) {
        if (arr[i] == number) {
            count++;
        }
    }
    printf("So lan xuat hien %d la: %d\n", number, count);
    return 0;
}