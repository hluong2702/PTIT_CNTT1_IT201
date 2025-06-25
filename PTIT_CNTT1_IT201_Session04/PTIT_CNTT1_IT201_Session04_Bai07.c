#include <stdio.h>
#include <stdlib.h>

int main() {
    int n , *arr;
    int found = 0;

    printf("Moi ban nhap vao so luong phan tu");
    scanf("%d",&n);

    arr = (int*)malloc(n*sizeof(int));
    for(int i = 0; i < n; i++) {
        printf("Phan tu thu %d ",i+1);
        scanf("%d",&arr[i]);
    }

    for(int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");

    for(int i = 0; i < n / 2; i++) {
        int temp = n - i - 1;
        printf("Cap doi xung: (%d,%d) \n ",arr[i],arr[temp]);
        found = 1;
    }
    if(found == 0) {
        printf("Khong co phan tu doi xung");
    }

    return 0;
}
