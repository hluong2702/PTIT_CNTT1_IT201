#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n;

    printf("Moi ban nhap vao so phan tu cua mang ");
    scanf("%d",&n);

    if (n <= 0) {
        printf("Khong hop le");
        return 0;
    }

    arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d ",i + 1);
        scanf("%d",&arr[i]);
    }
    int max = arr[0];
    int maxIndex = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
            maxIndex = i;
        }
    }
    printf("%d",maxIndex);
    free(arr);
    return 0;
}


