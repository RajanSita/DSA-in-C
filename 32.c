//WAP to evaluate Postfix expression using Stack.
#include <stdio.h>
#include <ctype.h> // For isdigit()
#include <stdlib.h> // For atoi()

#define MAX 100

int stack[MAX];
int top = -1;

// Stack operations
void push(int value) {
    if (top < MAX - 1) {
        stack[++top] = value;
    }
}

int pop() {
    if (top != -1) {
        return stack[top--];
    }
    return -1; // Stack underflow case
}

// Evaluate Postfix Expression
int evaluatePostfix(char postfix[]) {
    int i;
    for (i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        
        if (isdigit(ch)) {
            // If operand, push onto stack
            push(ch - '0'); // Convert char to int
        }
        else {
            // Operator: Pop two operands
            int val2 = pop();
            int val1 = pop();
            switch (ch) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
                case '^': {
                    int result = 1;
                    for (int j = 0; j < val2; j++) {
                        result *= val1;
                    }
                    push(result);
                    break;
                }
            }
        }
    }
    return pop();
}

int main() {
    printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
    printf("****************************\n");
    char postfix[MAX];

    printf("Enter a postfix expression (single-digit operands, no spaces): ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result after evaluation: %d\n", result);

    return 0;
}
