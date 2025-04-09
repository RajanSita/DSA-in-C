// WAP to implement two Singly Linked List that stores data as integer and
// perform following operation:
// Merge the two lists to create a new sorted list
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

// Insert a node at the end of the list
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

// Function to display a linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Merge two sorted linked lists into a new sorted list
struct Node* mergeSortedLists(struct Node* head1, struct Node* head2) {
    // If one list is empty, return the other
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* mergedHead = NULL;

    // Choose the head of the merged list
    if (head1->data < head2->data) {
        mergedHead = head1;
        head1 = head1->next;
    } else {
        mergedHead = head2;
        head2 = head2->next;
    }

    struct Node* mergedTail = mergedHead;

    // Merge both lists
    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            mergedTail->next = head1;
            head1 = head1->next;
        } else {
            mergedTail->next = head2;
            head2 = head2->next;
        }
        mergedTail = mergedTail->next;
    }

    // Attach the remaining elements
    if (head1 != NULL) {
        mergedTail->next = head1;
    } else {
        mergedTail->next = head2;
    }

    return mergedHead;
}

// Main function
int main() {
    printf("Rajan \t BCA 2A\nEnrolment No. \t 04717702024\n****************************\n");
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    struct Node* mergedHead = NULL;
    int n1, n2, data;

    printf("Enter the number of elements in first list: ");
    scanf("%d", &n1);
    printf("Enter elements (in sorted order) for the first list:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &data);
        insertAtEnd(&head1, data);
    }

    printf("Enter the number of elements in second list: ");
    scanf("%d", &n2);
    printf("Enter elements (in sorted order) for the second list:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &data);
        insertAtEnd(&head2, data);
    }

    printf("\nFirst List: ");
    displayList(head1);
    printf("Second List: ");
    displayList(head2);

    mergedHead = mergeSortedLists(head1, head2);

    printf("\nMerged Sorted List: ");
    displayList(mergedHead);

    return 0;
}
