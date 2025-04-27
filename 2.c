#include <stdio.h>

void linearSearch(int arr[], int size, int key) {
    int firstOccurrence = -1;
    printf("All occurrences of %d: ", key);

    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            if (firstOccurrence == -1)
                firstOccurrence = i; 
            printf("%d ", i);
        }
    }

    if (firstOccurrence == -1) {
        printf("\nElement not found.");
    } else {
        printf("\nFirst occurrence at index: %d\n", firstOccurrence);
    }
}

int main() {
	printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
	printf("****************************\n");
    int arr[] = {5, 2, 7, 2, 9, 2, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Enter the number to search: ");
    scanf("%d", &key);

    linearSearch(arr, size, key);

    return 0;
}

