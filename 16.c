//Write a Program to implement Bubble Sort.
#include <stdio.h>

#define SIZE 5  

void bubbleSort(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
    printf("****************************\n");
    int arr[SIZE];
    printf("Enter %d elements: ", SIZE);
    for (int i = 0; i < SIZE; i++)
        scanf("%d", &arr[i]);

    bubbleSort(arr, SIZE);

    printf("Sorted Array using Bubble Sort:\n");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", arr[i]);

    return 0;
}
