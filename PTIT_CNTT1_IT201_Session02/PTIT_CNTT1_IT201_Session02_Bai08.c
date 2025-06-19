#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *arr,count = 0;

    do {
        printf("Moi ban nhap so luong phan tu ");
        scanf("%d", &n);
    }while(n<=0);
    arr = (int*)malloc(n*sizeof(int));

    for(int i=0;i<n;i++) {
        printf("Nhap phan tu %d ", i+1);
        scanf("%d", &arr[i]);
    }

    for(int i=0;i<n;i++) {
        int flag=0;
        for(int j=i+1;j<n;j++) {
            if(arr[i]<arr[j]) {
                flag=1;
                break;
            }
        }
        if(flag==0) {
            printf("Phan tu co gia tri lon hon cac phan tu dung sau la %d \n", arr[i]);
            count++;
        }
    }
    if(!count) {
        printf("Khong tim thay");
    }
    free(arr);
    return 0;
}
