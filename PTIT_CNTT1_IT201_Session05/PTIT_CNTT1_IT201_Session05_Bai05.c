#include <stdio.h>
#include <string.h>

int palindrome(char *s, int left , int right) {
    if (left >= right) {
        return 1;
    }
    if (s[left] != s[right]) {
        return 0;
    }
    return palindrome(s, left + 1, right - 1);
}
int main() {
    char s[100];

    printf("Moi ban nhap");
    scanf("%s", s);

    int result = palindrome(s, 0, strlen(s) - 1);
    if (result) {
        printf("Palindrome valid");
    }else {
        printf("Palindrome invalid");
    }
    return 0;
}
