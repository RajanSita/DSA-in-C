//WAP to find factorial of a number using recursion
#include <stdio.h>

// Recursive function to calculate factorial
long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1; // Base case
    else
        return n * factorial(n - 1); // Recursive call
}

int main() {
    printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
    printf("****************************\n");
    int num;
    
    printf("Enter a number to find its factorial: ");
    scanf("%d", &num);
    
    if (num < 0)
        printf("Factorial is not defined for negative numbers.\n");
    else
        printf("Factorial of %d = %lld\n", num, factorial(num));
    
    return 0;
}
