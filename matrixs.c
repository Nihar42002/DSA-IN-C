#include<stdio.h>
#include<stdlib.h>

void addtion()
{
    int rows , columns;
    printf("Enter the number of rows and columns for the matrix: ");
    scanf("%d %d", &rows, &columns);

    int **matrix1 = (int **)malloc(rows * sizeof(int *));
    int **matrix2 = (int **)malloc(rows * sizeof(int *));
    int **result = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix1[i] = (int *)malloc(columns * sizeof(int));
        matrix2[i] = (int *)malloc(columns * sizeof(int));
        result[i] = (int *)malloc(columns * sizeof(int));
    }
    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }
    // Perform addition
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    // Display result
    printf("Resultant matrix after addition:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
}
 
void subtraction()
{
    int rows , columns;
    printf("Enter the number of rows and columns for the matrix: ");
    scanf("%d %d", &rows, &columns);

    int **matrix1 = (int **)malloc(rows * sizeof(int *));
    int **matrix2 = (int **)malloc(rows * sizeof(int *));
    int **result = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix1[i] = (int *)malloc(columns * sizeof(int));
        matrix2[i] = (int *)malloc(columns * sizeof(int));
        result[i] = (int *)malloc(columns * sizeof(int));
    }
    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }
    // Perform subtraction
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    // Display result
    printf("Resultant matrix after subtraction:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
}

void multiplication()
{
    int rows1, columns1, rows2, columns2;
    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &rows1, &columns1);
    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &rows2, &columns2);

    if (columns1 != rows2) {
        printf("Matrix multiplication not possible with given dimensions.\n");
        return;
    }

    int **matrix1 = (int **)malloc(rows1 * sizeof(int *));
    int **matrix2 = (int **)malloc(rows2 * sizeof(int *));
    int **result = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++) {
        matrix1[i] = (int *)malloc(columns1 * sizeof(int));
        result[i] = (int *)malloc(columns2 * sizeof(int));
    }
    for (int i = 0; i < rows2; i++) {
        matrix2[i] = (int *)malloc(columns2 * sizeof(int));
    }

    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns1; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < columns2; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }
    
    // Perform multiplication
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < columns1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    
    // Display result
    printf("Resultant matrix after multiplication:\n");
    for (int i = 0; i < rows1; i++) 
    {
        for (int j = 0; j < columns2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < rows1; i++) {
        free(matrix1[i]);
        free(result[i]);
    }
    for (int i = 0; i < rows2; i++) {
        free(matrix2[i]);
    }
}
    int main()
    {
        int choice;
        while (1)
         {
            printf("Matrix Operations Menu:\n");
            printf("1. Addition\n");
            printf("2. Subtraction\n");
            printf("3. Multiplication\n");
            printf("4. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) 
            {
                case 1:
                    addtion();
                    break;
                case 2:
                    subtraction();
                    break;
                case 3:
                    multiplication();
                    break;
                case 4:
                    printf("Exiting...\n");
                    break;

                default:
                    printf("Invalid choice, please try again.\n");
            }
        } 
    }

        
