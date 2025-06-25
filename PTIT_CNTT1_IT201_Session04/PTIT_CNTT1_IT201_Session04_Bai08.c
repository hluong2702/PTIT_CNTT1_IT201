#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr , n , x;
    int found = 0;

    printf("Moi ban nhap vao so luong phan tu ");
    scanf("%d",&n);

    arr = (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++) {
        printf("Phan tu thu %d ",i);
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");

    printf("Moi ban nhap gia tri can tim");
    scanf("%d",&x);

    for(int i=0;i<n;i++) {
        if(arr[i]==x) {
            printf(" %d ",i +1);
            found = 1;
        }
    }
    if(!found) {
        printf("Phan tu khong co trong mang");
        return 0;
    }
    free(arr);
    return 0;
}
