#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = val;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int evaluatePostfix(char* postfix) {
    char *p = postfix;
    int val1, val2, result;

    while (*p != '\0') {
        if (isdigit(*p)) {
            push(*p - '0');
        } else {
            val2 = pop();
            val1 = pop();

            switch (*p) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                default: printf("Invalid operator encountered.\n"); exit(1);
            }
            push(result);
        }
        p++;
    }

    return pop();
}

int main() {
    char postfix[MAX];
    printf("Enter Postfix Expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    printf("The result of the postfix expression is: %d\n", result);

    return 0;
}
