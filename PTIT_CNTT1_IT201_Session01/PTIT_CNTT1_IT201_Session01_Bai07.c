#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count = 1;
            }
        }
    }
    if (count == 1)
    {
        printf("Mang co phan tu trung lap");
    }
    else
    {
        printf("Mang khong co phan tu trung lap");
    }

    return 0;
}

// O(n2)