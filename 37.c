//Write a program to perform different operations such as insert, delete, display elements using dynamic queue.
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;

void insert() {
    int value;
    printf("Enter value to insert: ");
    scanf("%d", &value);

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Inserted: %d\n", value);
}
void delete() {
    if (front == NULL) {
        printf("Queue is empty (Underflow)\n");
        return;
    }

    struct Node* temp = front;
    printf("Deleted: %d\n", front->data);
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
    printf("****************************\n");
    int choice;
    do {
        printf("\n*** Dynamic Queue Menu ***\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: printf("Exiting program.\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
