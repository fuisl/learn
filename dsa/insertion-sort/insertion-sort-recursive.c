#include <stdio.h>
#include <stdlib.h>

void insertion_sort_recursive(int arr[], int n)
{
    if (n <= 1)
        return;

    insertion_sort_recursive(arr, n - 1);

    int last = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && arr[j] > last)
    {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = last;
}

int main()
{
    int n = 6;
    int arr[] = {5, 2, 4, 6, 1, 3};

    insertion_sort_recursive(arr, n);
    
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}