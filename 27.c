#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode; // Circular link
    return newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != *head) temp = temp->next;
    temp->next = newNode;
    newNode->next = *head;
}

void traverse(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Back to Head)\n");
}

void deleteAtEnd(Node** head) {
    if (*head == NULL) return;
    Node *temp = *head, *prev = NULL;
    while (temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }
    if (prev) prev->next = *head;
    else *head = NULL;
    free(temp);
}

int linearSearch(Node* head, int key) {
    if (head == NULL) return 0;
    Node* temp = head;
    do {
        if (temp->data == key) return 1;
        temp = temp->next;
    } while (temp != head);
    return 0;
}

int main() {
    printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
    printf("****************************\n");
    Node* head = NULL;
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    traverse(head);
    deleteAtEnd(&head);
    traverse(head);
    printf("Search 20: %s\n", linearSearch(head, 20) ? "Found" : "Not Found");
    return 0;
}
