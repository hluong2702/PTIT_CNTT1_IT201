#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *arr, sum;
    int flag = 0;

    do {
        printf("Moi ban nhap vao so luong phan tu ");
        scanf("%d",&n);
    }while(n<=0);
    arr = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++) {
        printf("Moi ban nhap phan tu %d ",i+1);
        scanf("%d",&arr[i]);
    }

    printf("Moi ban nhap vao tong so nguyen");
    scanf("%d",&sum);

    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(arr[i] + arr[j] == sum) {
                flag = 1;
                printf("Cap phan tu co tong %d la: %d ,%d",sum,arr[i],arr[j]);
            }
        }
    }
    if(flag==0) {
        printf("Khong tim thay");
    }
    free(arr);
    return 0;
}
