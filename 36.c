//Write a Program to Perform Pop, Push, Traverse operations on the stack using Pointer (Dynamic Stack).
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;
void push() {
    int value;
    printf("Enter value to push: ");
    scanf("%d", &value);

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed! Stack overflow.\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("Pushed %d onto the stack.\n", value);
}
void pop() {
    if (top == NULL) {
        printf("Stack Underflow! No elements to pop.\n");
        return;
    }

    struct Node* temp = top;
    printf("Popped element: %d\n", temp->data);
    top = top->next;
    free(temp);
}
void traverse() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node* temp = top;
    printf("Stack elements (Top to Bottom):\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
    printf("****************************\n");
    int choice;
    do {
        printf("\n*** Stack Menu (Using Pointers) ***\n");
        printf("1. Push\n2. Pop\n3. Traverse\n4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: traverse(); break;
            case 4: printf("Exiting program.\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
