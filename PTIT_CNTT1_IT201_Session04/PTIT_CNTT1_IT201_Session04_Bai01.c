#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr , n , x;
    int found = 0;

    printf("Moi ban nhap vao so luong phan tu ");
    scanf("%d",&n);

    arr = (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++) {
        printf("Phan tu thu %d ",i +1);
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");

    printf("Moi ban nhap gia tri can tim");
    scanf("%d",&x);
    int index = 0;

    for(int i=0;i<n;i++) {
        if(arr[i]==x) {
            index = i;
            break;
        }
    }
    if(index != 0) {
        printf("%d ",index);
    }else {
        printf("Khong tim thay phan tu");
    }

    free(arr);
    return 0;
}
