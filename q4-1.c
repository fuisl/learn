#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *matrix;
    int *arr;
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    matrix = (int *)malloc(rows * cols * sizeof(int));

    printf("Enter the elements of the matrix: \n");
    for (int i = 0; i < rows * cols; i++)
    {
        scanf("%d", &matrix[i]);
    }

    arr = (int *)malloc(rows * sizeof(int));
    int sum;

    for (int i = 0; i < rows; i++)
    {
        sum = 0;
        for (int j = 0; j < cols; j++)
        {
            if (j % 2 == 0)
                sum += matrix[i * cols + j];
        }
        arr[i] = sum;
    }

    printf("{");
    for (int i = 0; i < rows; i++)
    {
        printf("%d", arr[i]);
        if (i != rows - 1)
            printf(" ");
    }
    printf("}\n");

    return 0;
}