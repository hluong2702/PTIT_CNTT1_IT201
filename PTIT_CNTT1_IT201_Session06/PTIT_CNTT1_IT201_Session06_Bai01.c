#include <stdio.h>

void binary(int n) {
    if (n == 0) {
        printf("0");
        return;
    }
    if (n == 1) {
        printf("1");
        return;
    }
    binary(n / 2);
    printf("%d", n % 2);

}

int main() {
    int n;

    printf("Moi ban nhap vao so bat ki");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Khong hop le");
        return 0;
    }
    binary(n);
    return 0;
}