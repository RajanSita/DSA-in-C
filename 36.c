//Write a program to perform pop,push,traverseoperations on the stack using pointer(Dynamic Stack)
#include <stdio.h>
#include <stdlib.h>

// Structure to represent each node in the stack
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Push operation
void push() {
    int value;
    printf("Enter value to push: ");
    scanf("%d", &value);

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack Overflow (Memory allocation failed)\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d to stack\n", value);
}

// Pop operation
void pop() {
    if (top == NULL) {
        printf("Stack Underflow (Stack is empty)\n");
        return;
    }

    struct Node* temp = top;
    printf("Popped %d from stack\n", temp->data);
    top = top->next;
    free(temp);
}

// Traverse operation
void traverse() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    struct Node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main menu
int main() {
    int choice;
    do {
        printf("\n*** Stack Menu (Using Pointer) ***\n");
        printf("1. Push\n2. Pop\n3. Traverse\n4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: traverse(); break;
            case 4: printf("Exiting program.\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
