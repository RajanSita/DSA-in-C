#include <stdio.h>

#define ROW 4
#define COL 5
#define MAX 20  // Maximum non-zero elements

// Function to input a matrix
void inputMatrix(int mat[ROW][COL]) {
    printf("Enter elements of the matrix (%dx%d):\n", ROW, COL);
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            scanf("%d", &mat[i][j]);
}

// Function to display a matrix
void displayMatrix(int mat[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }
}

// Function to convert a matrix into sparse 3-tuple form
int convertToSparse(int mat[ROW][COL], int sparse[MAX][3]) {
    int k = 0; // Index for sparse matrix

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (mat[i][j] != 0) {
                sparse[k][0] = i;  // Row index
                sparse[k][1] = j;  // Column index
                sparse[k][2] = mat[i][j];  // Non-zero value
                k++;
            }
        }
    }
    
    return k; // Return count of non-zero elements
}

// Function to display the sparse matrix in 3-tuple notation
void displaySparseMatrix(int sparse[MAX][3], int count) {
    printf("\nSparse Matrix (3-Tuple Representation):\n");
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < count; i++)
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
}

int main() {
    // Print required details
    printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
    printf("****************************\n");

    int mat[ROW][COL], sparse[MAX][3];

    // Input matrix
    inputMatrix(mat);

    // Convert to sparse representation
    int nonZeroCount = convertToSparse(mat, sparse);

    // Display original matrix
    printf("\nOriginal Matrix:\n");
    displayMatrix(mat);

    // Display sparse matrix
    displaySparseMatrix(sparse, nonZeroCount);

    return 0;
}

