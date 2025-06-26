#include <stdio.h>
#include <stdlib.h>

void fibonacci(int arr[], int n,int index){
    if (index >= n ) {
        return;
    }
    if (index == 0) {
        arr[0] = 0;
    }else if (index == 1) {
        arr[1] = 1;
    }else {
        arr[index] = arr[index - 1] + arr[index - 2];
    }
    fibonacci(arr, n, index + 1);
}

int main() {
    int n ;
    printf("Moi ban nhap vao mot so nguyen duong bat ki");
    scanf("%d", &n);

    if (n <=0) {
        printf("Khong hop le");
        return 0;
    }

    int arr[100];
    fibonacci(arr,n ,0);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
