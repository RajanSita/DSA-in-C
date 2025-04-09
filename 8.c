#include <stdio.h>

int main() {
    // Print required details
    printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
    printf("****************************\n");

    int arr[10] = {10, 20, 30, 40, 50}; // Initial array
    int size = 5;  // Current number of elements
    int num, pos = -1;

    // Input number to search and delete
    printf("Enter the number to search and delete: ");
    scanf("%d", &num);

    // Search for the number
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            pos = i; // Store the position
            break;
        }
    }

    // If number is found, delete it
    if (pos != -1) {
        for (int i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--; // Reduce array size

        // Display updated array
        printf("Updated Array after deleting %d: ", num);
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
    } else {
        printf("Number not found in the array.\n");
    }

    return 0;
}

