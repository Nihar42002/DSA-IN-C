// multiplication of two matrices using arrays
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows1, columns1, rows2, columns2;

    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &rows1, &columns1);
    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &rows2, &columns2);

    // Check if multiplication is possible
    if (columns1 != rows2) {
        printf("Matrix multiplication not possible with given dimensions.\n");
        return 0;
    }
    // Allocate memory for matrices

    int arr1[rows1][columns1], arr2[rows2][columns2], result[rows1][columns2];
    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns1; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &arr1[i][j]);
        }
    }
    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < columns2; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &arr2[i][j]);
        }
    }

    // Initialize result matrix to zero
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++) {
            result[i][j] = 0;
        }
    }

    // Perform multiplication
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++) {
            for (int k = 0; k < columns1; k++) {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    // Print the result
    printf("Resultant matrix after multiplication:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0; // Return success

}