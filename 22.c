//WAP to implement a singly linked list that storesdata as integer and perform the following operations:
//Create a new list that reverse of the first linked list.
#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked list
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

// Function to insert a node at the end of the list
void insertEnd(struct Node** head, int data) {
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

// Function to reverse the linked list
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next; // Store next node
        current->next = prev; // Reverse current node's link
        prev = current;        // Move prev to this node
        current = next;        // Move to next node
    }
    return prev; // New head
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    printf("Rajan \t BCA 2A\nEnrolment No. \t 04717702024\n****************************\n");
    struct Node* head = NULL;
    struct Node* reversedHead = NULL;
    
    // Insert elements into the linked list
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);
    insertEnd(&head, 50);
    
    printf("Original List: ");
    printList(head);
    
    // Reverse the linked list
    reversedHead = reverseList(head);
    
    printf("Reversed List: ");
    printList(reversedHead);
    
    return 0;
}
