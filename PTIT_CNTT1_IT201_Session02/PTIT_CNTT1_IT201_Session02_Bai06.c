#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *arr, pos, value;

    do {
        printf("Moi ban nhap so luong phan tu ");
        scanf("%d", &n);
    }while(n <= 0 || n >100);
    arr = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("Moi ban nhap phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Mang goc la:");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    do {
        printf("Moi ban nhap vi tri can them ");
        scanf("%d",&pos);
    }while(pos < 0 || pos > n);

    printf("Nhap gia tri muon them:");
    scanf("%d", &value);

    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i -1 ];
    }
    arr[pos] = value;

    printf("Mang sau cap nhat la: ");
    for (int i = 0; i < n +1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
