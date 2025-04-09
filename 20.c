// WAP to implement Singly Linked List that stores data as integer and
// perform following operations:
// Insert a new node in the beginning and end of the list
// Insert a new node after a given node in the list.
// Insert a new node before a given node in the list.
#include <stdio.h>
#include <stdlib.h>

// Define structure for node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Insert at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert after a given node
void insertAfterNode(struct Node* head, int afterData, int data) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != afterData) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with data %d not found.\n", afterData);
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Insert before a given node
void insertBeforeNode(struct Node** head, int beforeData, int data) {
    // If list is empty
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // If beforeData is at head
    if ((*head)->data == beforeData) {
        insertAtBeginning(head, data);
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL && temp->next->data != beforeData) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Node with data %d not found.\n", beforeData);
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to display linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    printf("Rajan \t BCA 2A\nEnrolment No. \t 04717702024\n****************************\n");
    struct Node* head = NULL;
    int choice, data, afterData, beforeData;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After a Node\n");
        printf("4. Insert Before a Node\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter node data after which to insert: ");
                scanf("%d", &afterData);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAfterNode(head, afterData, data);
                break;
            case 4:
                printf("Enter node data before which to insert: ");
                scanf("%d", &beforeData);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertBeforeNode(&head, beforeData, data);
                break;
            case 5:
                displayList(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
