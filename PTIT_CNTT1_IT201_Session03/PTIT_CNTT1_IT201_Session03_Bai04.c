#include <stdio.h>
#include <stdlib.h>

void findMinMax(int rows , int cols , int **arr , int *min , int *max){
*max = arr[0][0];
*min = arr[0][0];
for(int i = 1 ; i < rows ; i++){
for(int j = 1 ; j < cols ; j++){
if(arr[i][j] > *max){
*max = arr[i][j];
}
if(arr[i][j] < *min){
*min = arr[i][j];}
}
}
}

int main(){
int rows , cols;
printf("Moi ban nhap so hang");
scanf("%d" , &rows);
printf("Moi ban nhap so cot");
scanf("%d" , &cols);

if(cols < 0) {
    printf("So cot khong hop le");
}
if(rows < 0){
printf("So hang khong hop le");}

    int **arr = (int **)malloc(rows * sizeof(int *));
    for(int i = 0 ; i < rows ; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }

    for(int i = 0 ; i < rows ; i++) {
        for(int j = 0 ; j < cols ; j++) {
            printf("Nhap phan tu tai [%d][%d] " , i,j);
            scanf("%d" , &arr[i][j]);
        }
    }

    int min , max ;
    findMinMax(rows , cols , arr , &min , &max);

    printf("Min = %d\n" , min);
    printf("Max = %d\n" , max);

    for(int i = 0 ; i < rows ; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}