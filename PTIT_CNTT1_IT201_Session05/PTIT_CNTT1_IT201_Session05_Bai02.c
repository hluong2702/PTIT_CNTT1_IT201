#include <stdio.h>

int sumRecursive(int n) {
    if(n <= 0 ) {
        return 0;
    }
    return n + sumRecursive(n-1);
}

int main() {
    int n;
    printf("Moi ban nhap vao mot chuoi bat ki ");
    scanf("%d",&n);

    if (n <= 0) {
        printf("Khong hop le");
        return -1;
    }

    printf("%d",sumRecursive(n));
    return 0;

}
