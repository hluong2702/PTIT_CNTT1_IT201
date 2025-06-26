#include <stdio.h>
void printf1ToN(int n, int i) {
    if (i > n) {
        return;
    }
    printf("%d",i);
    printf1ToN(n,i+1);
}


int main() {
    int n;
    printf("Moi ban nhap vao n: ");
    scanf("%d \n", &n);

    printf1ToN(n,1);
    return 0;
}