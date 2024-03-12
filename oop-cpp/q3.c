#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **matrix;
    int *arr;
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    matrix = (int **)malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Enter the elements of the matrix: \n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    arr = (int *)malloc(rows * sizeof(int));
    int sum = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] % 2 != 0)
                sum += matrix[i][j];
        }
        arr[i] = sum;
        sum = 0;
    }

    printf("{");
    for (int i = 0; i < rows; i++)
    {
        printf("%d", arr[i]);
        if (i != rows - 1)
            printf(" ");
    }
    printf("}\n");

    free(matrix);

    return 0;
}