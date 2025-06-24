#include <stdio.h>
#include <stdlib.h>

int sumMain(int **arr, int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        sum += arr[i][i];
    }
    return sum;
}

int sumExtra(int **arr, int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        sum += arr[i][cols - i - 1];
    }
    return sum;
}

int main() {
    int rows , cols;
    printf("Moi ban nhap so hang: ");
    scanf("%d", &rows);
    printf("Moi ban nhap so cot: ");
    scanf("%d", &cols);

    if (rows == 0 && cols == 0) {
        printf("So cot va so hang khong hop le: ");\
        return 0;
    }
    if (rows < 0 || cols < 0) {
        printf("So hang hoac so cot khong hop le");
        return 0;
    }
    if (rows != cols) {
        printf("Khong ton tai duong cheo chinh va duong cheo phu");
        return 0;
    }

    int **arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Nhap phan tu tai [%d][%d]" , i,j);
            scanf("%d", &arr[i][j]);
        }
    }

    int totalMainDiagonal = sumMain(arr, rows, cols);
    int totalSubdiagonal = sumExtra(arr, rows, cols);
    printf("Tong duong cheo chinh la %d\n ",totalMainDiagonal);
    printf("Tong duong cheo phu la %d ",totalSubdiagonal);

    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}
