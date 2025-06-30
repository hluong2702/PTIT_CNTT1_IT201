#include <stdio.h>
#include <string.h>

void bubbleSort(char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int main() {
    char str[100];

    printf("Moi ban nhap chuoi ki tu ");
    fgets(str, sizeof(str), stdin);
    int n = strlen(str);

    if (n == 0) {
        printf("Khong hop le");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
    bubbleSort(str, n);
    for (int i = 0; i < n; i++) {
        printf("%c", str[i]);
    }

}