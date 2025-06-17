#include <stdio.h>

int main() {
    int arr[] = {1, 1, 2, 4, 5, 6, 1, 1, 8, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int k = 0; k < i; k++) {
            if (arr[k] == arr[i]) {
                flag = 1;
                break;
            }
        }
        if (flag) continue;
        
        int count = 0; 
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        printf("Phan tu %d xuat hien %d lan\n", arr[i], count);
    }
    
    return 0;
}

// O(n)