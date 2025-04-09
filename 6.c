#include <stdio.h>

int main() {
	printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
	printf("****************************\n");

    int arr[10] = {10, 20, 30, 40, 50}; // Initial array
    int size = 5;  // Current number of elements
    int num, pos;

    // Input number and position
    printf("Enter the number to insert: ");
    scanf("%d", &num);
    printf("Enter the position (0 to %d): ", size);
    scanf("%d", &pos);

    // Validate position
    if (pos < 0 || pos > size) {
        printf("Invalid position! Position should be between 0 and %d.\n", size);
        return 1;
    }

    // Shift elements to the right
    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert new number
    arr[pos] = num;
    size++; // Increase size

    // Display updated array
    printf("Updated Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

