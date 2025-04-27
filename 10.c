//Write a Program to perform elimination of duplicate elements from an existing list of elements.
#include <stdio.h>

int main() {
    printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
    printf("****************************\n");

    int arr[] = {10, 20, 30, 20, 10, 40, 50, 50, 60}; 
    int size = sizeof(arr) / sizeof(arr[0]);
    int unique[size]; 
    int newSize = 0; 

    for (int i = 0; i < size; i++) {
        int found = 0; 
        for (int j = 0; j < newSize; j++) {
            if (arr[i] == unique[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            unique[newSize] = arr[i];
            newSize++;
        }
    }
    printf("Array after removing duplicates: ");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", unique[i]);
    }
    
    return 0;
}

