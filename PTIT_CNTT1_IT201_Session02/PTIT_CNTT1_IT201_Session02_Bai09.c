#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;
    int maxCount = 0;
    int maxNum;

    do {
        printf("Moi ban nhap so luong phan tu ");
        scanf("%d", &n);
    }while(n <= 0);
    arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Moi ban nhap phan tu thu %d ",i+1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            maxNum = arr[i];
        }
    }
    printf("Phan tu xuat hien nhieu nhat trong mang la %d ",maxNum);
    free(arr);
    return 0;
}