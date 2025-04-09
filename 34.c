//WAP to perform different operations with queue such as insert, delete, Display of elements using (Linear queue or static Queue)
#include <stdio.h>
#define SIZE 100

int queue[SIZE];
int front = -1, rear = -1;

void insert() {
    int item;
    if (rear == SIZE - 1) {
        printf("Queue is full (Overflow)\n");
        return;
    }
    printf("Enter the element to insert: ");
    scanf("%d", &item);
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = item;
    printf("Element inserted: %d\n", item);
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue is empty (Underflow)\n");
        return;
    }
    printf("Element deleted: %d\n", queue[front]);
    front++;
    if (front > rear) {
        // Reset queue if all elements are removed
        front = rear = -1;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    do {
        printf("\n*** Queue Menu ***\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: printf("Exiting program.\n"); break;
            default: printf("Invalid choice! Please enter 1-4.\n");
        }
    } while(choice != 4);

    return 0;
}
