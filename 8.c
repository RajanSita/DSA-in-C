#include <stdio.h>

int main() {
    printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
    printf("****************************\n");

    int arr[10] = {10, 20, 30, 40, 50}; 
    int size = 5; 
    int num, pos = -1;
    printf("Enter the number to search and delete: ");
    scanf("%d", &num);
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            pos = i; 
            break;
        }
    }
    if (pos != -1) {
        for (int i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--; 
        printf("Updated Array after deleting %d: ", num);
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
    } else {
        printf("Number not found in the array.\n");
    }

    return 0;
}

