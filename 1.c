#include <stdio.h>
// This program demonstrates the use of arrays in C.
int main() {
	printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
	printf("****************************\n");
    // (a) Compile-time initialization of an integer array
    int intArr[] = {10, 20, 30, 40, 50};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);

    // (b) Run-time initialization of a float array
    float floatArr[5];
    int floatSize = 5;

    printf("Enter 5 floating-point numbers:\n");
    for (int i = 0; i < floatSize; i++) {
        scanf("%f", &floatArr[i]);
    }

    // (c) Display both arrays with proper headings
    printf("\nInteger Array Elements:\n");
    for (int i = 0; i < intSize; i++) {
        printf("%d ", intArr[i]);
    }

    printf("\nFloating-Point Array Elements:\n");
    for (int i = 0; i < floatSize; i++) {
        printf("%.2f ", floatArr[i]);
    }

    return 0;
}
