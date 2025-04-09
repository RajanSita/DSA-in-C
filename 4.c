#include <stdio.h>
// This program demonstrates the merging of two unsorted arrays into a single array.
void mergeArrays(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    int i, j;
    // Initialize merged array with size equal to the sum of both arrays
    // Copy elements of arr1 into merged array
    for (i = 0; i < size1; i++) {
        merged[i] = arr1[i];
    }

    // Copy elements of arr2 into merged array
    for (j = 0; j < size2; j++) {
        merged[i + j] = arr2[j];
    }
}

int main() {
	printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
	printf("****************************\n");
    // Define two unsorted arrays
    int arr1[] = {5, 2, 8};
    int arr2[] = {1, 7, 3, 6};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int merged[size1 + size2]; // Merged array

    // Merge the arrays
    mergeArrays(arr1, size1, arr2, size2, merged);

    // Display the merged array
    printf("Merged Unsorted Array: ");
    for (int i = 0; i < (size1 + size2); i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}

