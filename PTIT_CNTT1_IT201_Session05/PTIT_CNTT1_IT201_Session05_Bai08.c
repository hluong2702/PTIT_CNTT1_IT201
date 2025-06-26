#include <ctype.h>
#include <stdio.h>
#include <string.h>

int stringto(char *s,int index, int result , int *isValid) {
    if (index >= strlen(s)) {
        return result;
    }
    if (!isdigit(s[index])) {
        *isValid = 0;
        return 0;
    }

    int digit = s[index] - '0';
    return stringto(s, index+1, result * 10 + digit, isValid);
}

int main() {
    char s[100];
    int isValid = 1;

    printf("Moi ban nhap ");
    scanf("%s",s);

    int result = stringto(s,0,0,&isValid);
    if (isValid) {
        printf("%d",result);
    }else {
        printf("Khong hop le");
    }
    return 0;
}