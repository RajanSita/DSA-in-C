#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if(top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed onto stack\n", value);
    }
}

void pop() {
    if(top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d popped from stack\n", stack[top]);
        top--;
    }
}

void display() {
    if(top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for(int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    return 0;
}
