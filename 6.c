#include <stdio.h>

int main() {
	printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
	printf("****************************\n");

    int arr[10] = {10, 20, 30, 40, 50}; 
    int size = 5; 
    int num, pos;
    printf("Enter the number to insert: ");
    scanf("%d", &num);
    printf("Enter the position (0 to %d): ", size);
    scanf("%d", &pos);
    if (pos < 0 || pos > size) {
        printf("Invalid position! Position should be between 0 and %d.\n", size);
        return 1;
    }

    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = num;
    size++; 

    printf("Updated Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

