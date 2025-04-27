// WAP to implement Singly Linked List that stores data as integer and perform following operations:
// Traverse the list to display each element
// Search for a specific element in the list
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (temp->next != NULL) 
        temp = temp->next;

    temp->next = newNode;
}

void traverse(struct Node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void search(struct Node* head, int key) {
    int pos = 1;
    while (head != NULL) {
        if (head->data == key) {
            printf("Element %d found at position %d.\n", key, pos);
            return;
        }
        head = head->next;
        pos++;
    }
    printf("Element %d not found in the list.\n", key);
}

int main() {
    printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
    printf("****************************\n");
    struct Node* head = NULL;
    int n, value, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert(&head, value);
    }

    traverse(head);

    printf("Enter element to search: ");
    scanf("%d", &key);
    search(head, key);

    return 0;
}
