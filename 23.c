// WAP to implement Singly Linked List that stores data as integer and
// perform following operations:
// Delete a node in the beginning and end of the list.
// Delete the node that comes after a given node in the linked list.
// Search an element in the linked list. If found, delete it.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

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

void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Node deleted from the beginning.\n");
}
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Node deleted from the end.\n");
        return;
    }
    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("Node deleted from the end.\n");
}

void deleteAfterNode(struct Node* head, int afterData) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != afterData) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("No node found after the given node or given node not found.\n");
        return;
    }
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    printf("Node deleted after node with data %d.\n", afterData);
}
void searchAndDelete(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found.\n", key);
        return;
    }

    if (prev == NULL) {
        *head = (*head)->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Element %d found and deleted.\n", key);
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
    printf("****************************\n");
    struct Node* head = NULL;
    int choice, data, afterData, searchKey;

    while (1) {
        printf("\n--- Singly Linked List Operations ---\n");
        printf("1. Insert at End\n");
        printf("2. Delete from Beginning\n");
        printf("3. Delete from End\n");
        printf("4. Delete After a Given Node\n");
        printf("5. Search and Delete an Element\n");
        printf("6. Display List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 2:
                deleteAtBeginning(&head);
                break;
            case 3:
                deleteAtEnd(&head);
                break;
            case 4:
                printf("Enter node data after which to delete: ");
                scanf("%d", &afterData);
                deleteAfterNode(head, afterData);
                break;
            case 5:
                printf("Enter element to search and delete: ");
                scanf("%d", &searchKey);
                searchAndDelete(&head, searchKey);
                break;
            case 6:
                displayList(head);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
