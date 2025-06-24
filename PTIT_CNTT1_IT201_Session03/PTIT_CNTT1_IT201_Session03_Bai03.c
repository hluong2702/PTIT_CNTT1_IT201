#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;
    int sum = 0;
    int count = 0;

    printf("Moi ban nhap so luong phan tu ");
    scanf("%d", &n);

    if (n < 0 || n == 0 || n > 1000) {
        printf("So luong phan tu khong hop le");
    }
    arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Moi ban nhap phan tu thu %d ",i +1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0 ; i < n; i++) {
        if (arr[i] % 2 == 0) {
            sum += arr[i];
            count++;
        }
    }
    printf("average = %d ",sum/count);
    free(arr);
    return 0;
}
