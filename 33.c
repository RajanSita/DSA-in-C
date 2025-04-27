//WAP to reverse the String using Stack
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

void reverseString(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        push(str[i]);
    }

    for (int i = 0; i < strlen(str); i++) {
        str[i] = pop();
    }
}

int main() {
    printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
    printf("****************************\n");
    char str[MAX];
    printf("Enter a string to reverse: ");
    scanf("%s", str);

    reverseString(str);
    printf("Reversed string: %s\n", str);

    return 0;
}
