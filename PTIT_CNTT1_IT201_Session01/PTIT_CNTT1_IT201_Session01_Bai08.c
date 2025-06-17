#include <stdio.h>

int main(){
    int arr[] = {1,2,4,24,5,45,3,234,3,3,2,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int count = 0;
    int maxCount = 0;
    int maxElement = arr[0];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
            
        }
        if (count > maxCount)
        {
            maxCount = count;
            maxElement = arr[i];
        }
    }
    printf("Phan tu xuat hien nhieu nhat trong mang la : %d",maxElement);
    return 0;

}

// O(n2)