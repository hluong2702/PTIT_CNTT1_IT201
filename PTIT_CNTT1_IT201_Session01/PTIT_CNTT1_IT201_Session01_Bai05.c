#include <stdio.h>

int main(){
    int arr[] = {34,42,3,1,9,7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Mang ban dau la:");
    for (int i = 0; i < n ; i++)
    {
        printf(" %d",arr[i]);
    }
    printf(" \n");

    for (int i = 0; i < n-1; i++)
    {
       for (int j = 0; j < n-i-1; j++)
       {
        if (arr[j] > arr[j +1])
        {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
        
       }
       
    }

    printf("Mang sau khi dc sap xep la: ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d",arr[i]);
    }
    printf("\n");

    return 0;
}

// O(n2)