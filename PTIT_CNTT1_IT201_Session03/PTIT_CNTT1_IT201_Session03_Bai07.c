#include <stdio.h>
#include <stdlib.h>

int sumK(int **arr, int rows, int cols, int k) {
    int sum = 0;
    for (int j = 0; j < cols; j++) {
        sum += arr[k - 1][j];
    }
    return sum;
}

int main() {
    int rows, cols, k;
    printf("Moi ban nhap vao so hang");
    scanf("%d",&rows);
    printf("Moi ban nhap vao so cot");
    scanf("%d",&cols);

    if (rows <= 0 || cols <= 0) {
        printf("So hang hoac so cot khong hop le");
        return 0;
    }

    int **arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Moi ban nhap vao [%d][%d]", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Moi ban nhap vao vi tri hang can tinh");
    scanf("%d",&k);

    if (k <= 0 || k > rows) {
        printf("Hang can tinh khong ton tai");
    }

    int rowSum = sumK( arr , rows, cols, k);
    printf("Sum = %d", rowSum);

    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}
