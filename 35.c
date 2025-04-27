//WAP to perform different operations with queue such as insert delete,Display of elements using circular Queue
#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void insert() {
    int item;
    if ((front == 0 && rear == SIZE - 1) || (rear + 1) % SIZE == front) {
        printf("Queue is full (Overflow)\n");
        return;
    }
    printf("Enter the element to insert: ");
    scanf("%d", &item);
    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    queue[rear] = item;
    printf("Inserted: %d\n", item);
}

void delete() {
    if (front == -1) {
        printf("Queue is empty (Underflow)\n");
        return;
    }
    printf("Deleted: %d\n", queue[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
    printf("****************************\n");
    int choice;
    do {
        printf("\n*** Circular Queue Menu ***\n");
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
