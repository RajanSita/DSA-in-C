//Write a program to calculate the GCD of two numbers using recursive functions
#include <stdio.h>

// Recursive function to find GCD
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
    printf("****************************\n");
    int num1, num2;

    printf("Enter two positive integers: ");
    scanf("%d %d", &num1, &num2);

    if (num1 <= 0 || num2 <= 0) {
        printf("Please enter positive integers only.\n");
        return 0;
    }

    printf("GCD of %d and %d is: %d\n", num1, num2, gcd(num1, num2));

    return 0;
}
