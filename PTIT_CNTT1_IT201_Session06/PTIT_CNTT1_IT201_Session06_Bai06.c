#include <stdio.h>

int countWay(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    return countWay(n - 1) + countWay(n - 2);
}

int main() {
    int n;

    printf("Moi ban nhap so bac");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Khong hop le");
        return 0;
    }
    int ways = countWay(n);
    printf("So cach de leo het %d bac cau thang : %d\n",n , ways);
    return 0;
}