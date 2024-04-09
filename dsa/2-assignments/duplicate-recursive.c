#include <stdio.h>
#include <stdlib.h>

int duplicate_recursive(int arr[], int n)
{
    if (n <= 1)
        return 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[n - 1])
            return 1;
    }

    return duplicate_recursive(arr, n - 1);
}

int main()
{
    int n = 6;
    int arr[] = {4, 2, 5, 6, 1, 3};

    if (duplicate_recursive(arr, n))
        printf("Array contains duplicate elements.");
    else
        printf("Array does not contain duplicate elements.");

    return 0;
}