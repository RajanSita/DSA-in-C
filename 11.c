//Create a Matrix. Perform addition, subtraction, Transpose and Multiplication using Switch-Case statement.
#include <stdio.h>

#define ROW 3
#define COL 3

void inputMatrix(int mat[ROW][COL], char name) {
    printf("Enter elements of Matrix %c (%dx%d):\n", name, ROW, COL);
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

void matrixOperations(int A[ROW][COL], int B[ROW][COL], int choice) {
    int result[ROW][COL], i, j, k;
    
    switch (choice) {
        case 1: // Addition
            for (i = 0; i < ROW; i++)
                for (j = 0; j < COL; j++)
                    result[i][j] = A[i][j] + B[i][j];
            printf("\nMatrix Addition Result:\n");
            break;
        
        case 2: // Subtraction
            for (i = 0; i < ROW; i++)
                for (j = 0; j < COL; j++)
                    result[i][j] = A[i][j] - B[i][j];
            printf("\nMatrix Subtraction Result:\n");
            break;

        case 3: // Transpose of A
            for (i = 0; i < ROW; i++)
                for (j = 0; j < COL; j++)
                    result[j][i] = A[i][j];
            printf("\nTranspose of First Matrix:\n");
            break;

        case 4: // Multiplication
            for (i = 0; i < ROW; i++)
                for (j = 0; j < COL; j++) {
                    result[i][j] = 0;
                    for (k = 0; k < COL; k++)
                        result[i][j] += A[i][k] * B[k][j];
                }
            printf("\nMatrix Multiplication Result:\n");
            break;

        default:
            printf("Invalid choice!\n");
            return;
    }
    displayMatrix(result);
}

int main() {
    printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
    printf("****************************\n");

    int A[ROW][COL], B[ROW][COL], choice;
    
    inputMatrix(A, 'A');
    inputMatrix(B, 'B');

    do {
        printf("\nChoose an operation:\n1. Addition\n2. Subtraction\n3. Transpose of A\n4. Multiplication\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 5) break;
        matrixOperations(A, B, choice);
    } while (choice != 5);

    return 0;
}

