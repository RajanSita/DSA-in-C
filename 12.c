//Read and display Upper, Lower and Tri-diagonal matrices
#include <stdio.h>

#define SIZE 3 
void inputMatrix(int mat[SIZE][SIZE]) {
    printf("Enter elements of the matrix (%dx%d):\n", SIZE, SIZE);
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            scanf("%d", &mat[i][j]);
}
void displayMatrix(int mat[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }
}
void upperTriangular(int mat[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            result[i][j] = (i <= j) ? mat[i][j] : 0;
}
void lowerTriangular(int mat[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            result[i][j] = (i >= j) ? mat[i][j] : 0;
}
void triDiagonal(int mat[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            result[i][j] = (i == j || i == j + 1 || i == j - 1) ? mat[i][j] : 0;
}

int main() {
    printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
    printf("****************************\n");

    int mat[SIZE][SIZE], upper[SIZE][SIZE], lower[SIZE][SIZE], triDiag[SIZE][SIZE];

    inputMatrix(mat);

    upperTriangular(mat, upper);
    lowerTriangular(mat, lower);
    triDiagonal(mat, triDiag);

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

