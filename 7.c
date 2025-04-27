#include <stdio.h>

int main() {
	printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
	printf("****************************\n");

    int arr[10] = {10, 20, 30, 40, 50}; 
    int size = 5;  
    int pos;
    printf("Enter the position to delete (0 to %d): ", size - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= size) {
        printf("Invalid position! Position should be between 0 and %d.\n", size - 1);
        return 1;
    }
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--; 
    printf("Updated Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

