// WAP to Convert Infix Expression to Postfix form using Stack.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
        return -1;
    }
    return stack[top--];
}

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(char* infix) {
    char *p = infix;
    char ch;

    printf("Postfix Expression: ");

    while (*p != '\0') {
        if (isalnum(*p)) {
            printf("%c", *p);
        } else if (*p == '(') {
            push(*p);
        } else if (*p == ')') {
            while ((ch = pop()) != '(') {
                printf("%c", ch);
            }
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(*p)) {
                printf("%c", pop());
            }
            push(*p);
        }
        p++;
    }

    while (top != -1) {
        printf("%c", pop());
    }
    printf("\n");
}

int main() {
    char infix[MAX];
    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);
    return 0;
}