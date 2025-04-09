#include <stdio.h>

int main() {
    // Print required details
    printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
    printf("****************************\n");

    int arr[] = {10, 20, 30, 20, 10, 40, 50, 50, 60}; // Original array with duplicates
    int size = sizeof(arr) / sizeof(arr[0]);
    int unique[size]; // Array to store unique elements
    int newSize = 0; // Track unique elements count

    // Iterate through original array
    for (int i = 0; i < size; i++) {
        int found = 0; // Flag to check if element is already added

        // Check if the element is already in unique array
        for (int j = 0; j < newSize; j++) {
            if (arr[i] == unique[j]) {
                found = 1;
                break;
            }
        }

        // If not found, add to unique array
        if (!found) {
            unique[newSize] = arr[i];
            newSize++;
        }
    }

    // Display the updated array without duplicates
    printf("Array after removing duplicates: ");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", unique[i]);
    }
    
    return 0;
}

