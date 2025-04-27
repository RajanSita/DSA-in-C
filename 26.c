#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

void deleteAtBeginning(Node** head) {
    if (*head == NULL) return;
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteAtEnd(Node** head) {
    if (*head == NULL) return;
    Node* temp = *head, *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev) prev->next = NULL;
    else *head = NULL;
    free(temp);
}

void traverse(Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
    printf("****************************\n");
    Node* head = NULL;
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    traverse(head);
    deleteAtBeginning(&head);
    traverse(head);
    deleteAtEnd(&head);
    traverse(head);
    return 0;
}
