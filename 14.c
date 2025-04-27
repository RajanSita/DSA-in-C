//Write a Program to implement Selection Sort.
#include <stdio.h>

#define SIZE 5 
void inputArray(int arr[], int size) {
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void selectionSort(int arr[], int size) {
    int i, j, minIndex, temp;
    
    for (i = 0; i < size - 1; i++) {
        minIndex = i;

        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
    printf("****************************\n");

    int arr[SIZE];

    inputArray(arr, SIZE);

    selectionSort(arr, SIZE);

    printf("\nSorted Array using Selection Sort:\n");
    displayArray(arr, SIZE);

    return 0;
}

