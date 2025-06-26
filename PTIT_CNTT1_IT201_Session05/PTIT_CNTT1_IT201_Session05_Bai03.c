#include <stdio.h>

int factorialRecursive(int n) {
    if(n == 0) {
        return 1;
    }
    return n * factorialRecursive(n -1);
}

int main() {
    int n;
    printf("Moi ban nhap vao mot so nguyen bat ki");
    scanf("%d",&n);

    if(n <= 0) {
        printf("Khong hop le");
        return 0 ;
    }

    printf("%d",factorialRecursive(n));
    return 0;

}