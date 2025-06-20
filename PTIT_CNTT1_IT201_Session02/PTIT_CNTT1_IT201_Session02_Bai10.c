#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;
    int count=0;
    do {
        printf("Moi ban nhap so luong phan tu ");
        scanf("%d ",&n);
    }while(n<=0);
    arr = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++) {
        printf("Nhap phan tu thu %d ",i+1);
        scanf("%d",&arr[i]);
    }

    int *visited = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        if (visited[i] == 1) continue;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1;
            }
        }
        if (count > 0) {
            printf("Phan tu %d xuat hien %d lan ",arr[i],count);
        }
    }

    free(arr);
    free(visited);
    return 0;
}
