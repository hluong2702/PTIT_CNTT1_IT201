#include <stdio.h>

int main() {
    int n = 10;
    // cach1
    int sum1 = 0;
    for (int i = 1; i <= n; i++) {
        sum1 += i;
    }
    printf("Tong: %d\n", sum1);
    // O(n)
    
    // cach2
    int sum2 = n * (n + 1) / 2;
    printf("Tong: %d\n", sum2);
    // O(1)
    return 0;

}