#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (arr[mid] == key)
            return mid; 

        if (arr[mid] < key)
            low = mid + 1; 
        else
            high = mid - 1; 
    }
    return -1; 
}

int main() {
    printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
    printf("****************************\n");

    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72}; 
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;
    printf("Enter the number to search: ");
    scanf("%d", &key);
    int result = binarySearch(arr, size, key);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found.\n");

    return 0;
}

