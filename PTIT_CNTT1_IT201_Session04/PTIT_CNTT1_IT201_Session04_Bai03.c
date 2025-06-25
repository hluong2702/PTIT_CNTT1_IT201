#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *arr;

    printf("Moi ban nhap so luong phan tu ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Khong hop le");
        return 0;
    }

    arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Phan tu %d ", i + 1);
        scanf("%d", &arr[i]);
    }

    int min = arr[0];
    int minIndex = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
            minIndex = i;
        }
    }

    printf("%d", minIndex);
    free(arr);
    return 0;
}
