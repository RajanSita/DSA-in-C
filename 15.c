#include <stdio.h>

#define SIZE 5  

void insertionSort(int arr[], int size) {
    int i, j, key;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    printf("Rajan \t BCA 2A\nEnrolment No. \t 04717702024\n****************************\n");

    int arr[SIZE];
    printf("Enter %d elements: ", SIZE);
    for (int i = 0; i < SIZE; i++)
        scanf("%d", &arr[i]);

    insertionSort(arr, SIZE);

    printf("Sorted Array using Insertion Sort:\n");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", arr[i]);

    return 0;
}
