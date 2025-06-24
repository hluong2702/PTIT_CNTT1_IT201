#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;

    printf("Moi ban nhap vao so luong phan tu");
    scanf("%d", &n);
    if (n < 0) {
        printf("So luong phan tu khong duoc am");
    }else if (n == 0) {
        printf("So luong phan tu phai lon hon khong");
    }
    arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Moi ban nhap phan tu thu %d ", i +1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("So thu %d = %d \n",i +1, arr[i]);
    }
    free(arr);
    return 0;
}
