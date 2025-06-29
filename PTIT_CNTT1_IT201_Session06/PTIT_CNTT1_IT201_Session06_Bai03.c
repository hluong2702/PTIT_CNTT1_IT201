#include <stdio.h>

int sum(int n) {
    if (n< 10) {
        return n;
    }
    return sum(n / 10) + n % 10;
}

int main() {
    int n;

    printf("Moi ban nhap vao so nguyen n ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Khong hop le");
        return 0;
    }

    int result = sum(n);
    printf("%d", result);
    return 0;
}