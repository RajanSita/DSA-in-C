#include <stdio.h>

int main() {
	printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
	printf("****************************\n");
    int arr[] = {12, 5, 8, 19, 3, 25, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int min = arr[0], max = arr[0], sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
        sum += arr[i]; 
    }
    float average = (float)sum / size;
    printf("Array Elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nMinimum Element: %d", min);
    printf("\nMaximum Element: %d", max);
    printf("\nSum of Elements: %d", sum);
    printf("\nAverage of Elements: %.2f\n", average);

    return 0;
}
 	
