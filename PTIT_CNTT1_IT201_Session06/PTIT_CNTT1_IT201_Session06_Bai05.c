#include <stdio.h>

int findMin(int arr[],int size,int index) {
    if (index == size - 1) {
        return arr[index];
    }
    int min = findMin(arr, size, index + 1);
    return (arr[index] < min) ? arr[index] : min;
}

int findMax(int arr[],int size,int index) {
    if (index == size - 1) {
        return arr[index];
    }
    int max = findMax(arr, size, index + 1);
    return (arr[index] > max) ? arr[index] : max;
}

int main() {
    int n;

    printf("Moi ban nhap vao so phan tu cua mang");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Khong hop le");
        return 0;
    }
    int arr[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int min = findMin(arr, n, 0);
    int max = findMax(arr, n, 0);
    printf("%d \n", min);
    printf("%d", max);
    return 0;

}