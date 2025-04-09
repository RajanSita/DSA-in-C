#include <stdio.h>

#define SIZE 3  // Define matrix size (3x3 for simplicity)

// Function to input a matrix
void inputMatrix(int mat[SIZE][SIZE]) {
    printf("Enter elements of the matrix (%dx%d):\n", SIZE, SIZE);
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            scanf("%d", &mat[i][j]);
}

// Function to display a matrix
void displayMatrix(int mat[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }
}

// Function to extract Upper Triangular Matrix
void upperTriangular(int mat[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            result[i][j] = (i <= j) ? mat[i][j] : 0;
}

// Function to extract Lower Triangular Matrix
void lowerTriangular(int mat[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            result[i][j] = (i >= j) ? mat[i][j] : 0;
}

// Function to extract Tri-diagonal Matrix
void triDiagonal(int mat[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            result[i][j] = (i == j || i == j + 1 || i == j - 1) ? mat[i][j] : 0;
}

int main() {
    // Print required details
    printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
    printf("****************************\n");

    int mat[SIZE][SIZE], upper[SIZE][SIZE], lower[SIZE][SIZE], triDiag[SIZE][SIZE];

    // Input matrix
    inputMatrix(mat);

    // Generate different matrix types
    upperTriangular(mat, upper);
    lowerTriangular(mat, lower);
    triDiagonal(mat, triDiag);

    // Display results
    printf("\nOriginal Matrix:\n");
    displayMatrix(mat);

    printf("\nUpper Triangular Matrix:\n");
    displayMatrix(upper);

    printf("\nLower Triangular Matrix:\n");
    displayMatrix(lower);

    printf("\nTri-Diagonal Matrix:\n");
    displayMatrix(triDiag);

    return 0;
}

