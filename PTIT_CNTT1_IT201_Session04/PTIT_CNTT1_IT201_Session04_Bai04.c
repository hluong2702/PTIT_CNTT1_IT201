#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr, n , value;

    printf("Moi ban nhap vao so luong phan tu ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("So luong phan tu khong hop le");
        return 0;
    }

    arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Phan tu %d ",i+1);
        scanf("%d", &arr[i]);
    }

    printf("Moi ban nhap vao mot so bat ki");
    scanf("%d", &value);

    int index = 0;

    for (int i = 0; i < n; i++) {
        if (arr[n-1] == value) {
            index = i;
        }
        if (arr[n-1] != value) {
            printf("Khong tim thay phan tu");
            return 0;
        }
    }
    printf(" %d ",index);
    free(arr);
    return 0;
}