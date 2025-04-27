//WAP to Convert Infix Expression to Prefix form using Stack.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top != -1) {
        return stack[top--];
    }
    return '\0';
}

char peek() {
    if (top != -1) {
        return stack[top];
    }
    return '\0';
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

void reverse(char exp[]) {
    int len = strlen(exp);
    for (int i = 0; i < len/2; i++) {
        char temp = exp[i];
        exp[i] = exp[len-i-1];
        exp[len-i-1] = temp;
    }
}

void infixToPrefix(char infix[], char prefix[]) {
    int i, j = 0;
    int len = strlen(infix);
    reverse(infix);

    for (i = 0; i < len; i++) {
        char ch = infix[i];
        
        if (isalnum(ch)) { 
            prefix[j++] = ch;
        }
        else if (ch == ')') {
            push(ch);
        }
        else if (ch == '(') {
            while (top != -1 && peek() != ')') {
                prefix[j++] = pop();
            }
            if (top != -1) {
                pop(); 
            }
        }
        else { 
            while (top != -1 && precedence(peek()) > precedence(ch)) {
                prefix[j++] = pop();
            }
            push(ch);
        }
    }

    while (top != -1) {
        prefix[j++] = pop();
    }

    prefix[j] = '\0';
    reverse(prefix);
}

int main() {
    printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
    printf("****************************\n");
    char infix[MAX], prefix[MAX];

    printf("Enter infix expression (no spaces): ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
