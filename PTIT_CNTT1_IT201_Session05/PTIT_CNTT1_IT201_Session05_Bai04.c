#include <stdio.h>

int sumRecursive(int n, int k) {
    if (n > k ) {
        return 0;
    }
    return sumRecursive(n +1, k) + n ;

}

int main() {
    int firstNum, secondNum;
    printf("Moi ban nhapao so thu 1");
    scanf("%d",&firstNum);
    printf("Moi ban nhap vao so thu 2");
    scanf("%d",&secondNum);

    if (firstNum <= 0 || secondNum <= 0) {
        printf("Khong hop le");
        return -1;
    }

    printf("%d",sumRecursive(firstNum,secondNum));
    return 0;
}