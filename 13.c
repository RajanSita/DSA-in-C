//Implement sparse matrices using 3-tuple notation.
#include <stdio.h>

#define ROW 4
#define COL 5
#define MAX 20  
void inputMatrix(int mat[ROW][COL]) {
    printf("Enter elements of the matrix (%dx%d):\n", ROW, COL);
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            scanf("%d", &mat[i][j]);
}
void displayMatrix(int mat[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }
}
int convertToSparse(int mat[ROW][COL], int sparse[MAX][3]) {
    int k = 0; 

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (mat[i][j] != 0) {
                sparse[k][0] = i;  
                sparse[k][1] = j;  
                sparse[k][2] = mat[i][j];  
                k++;
            }
        }
    }
    
    return k; 
}

void displaySparseMatrix(int sparse[MAX][3], int count) {
    printf("\nSparse Matrix (3-Tuple Representation):\n");
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < count; i++)
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
}

int main() {
    printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
    printf("****************************\n");

    int mat[ROW][COL], sparse[MAX][3];

    inputMatrix(mat);

    int nonZeroCount = convertToSparse(mat, sparse);

    printf("\nOriginal Matrix:\n");
    displayMatrix(mat);

    displaySparseMatrix(sparse, nonZeroCount);

    return 0;
}

