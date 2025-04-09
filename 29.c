#include <stdio.h>
#define SIZE 5

int stack[SIZE], top = -1;

void push(int data) {
    if (top == SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = data;
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    top--;
}

void traverse() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    printf("Rajan \t BCA 2A\nEnrolment No. \t 04717702024\n****************************\n");
    push(10);
    push(20);
    push(30);
    traverse();
    pop();
    traverse();
    return 0;
}
