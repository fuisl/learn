#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **matrix;
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

    if (rows > cols)  // choose the smaller dimension
    {
        int temp = rows;
        rows = cols;
        cols = temp;
    }

    int res = 0;
    for (int i = 0; i < rows; i++)
    {
        res += (matrix[i][i] * matrix[i][i]);
    }
    
    printf("%d", res);

    free(matrix);

    return 0;
}