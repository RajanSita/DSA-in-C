// WAP to implement two Singly Linked List that stores data as integer and
// perform following operation:
// Merge the two lists to create a new sorted list
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
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* mergeSortedLists(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* mergedHead = NULL;
    if (head1->data < head2->data) {
        mergedHead = head1;
        head1 = head1->next;
    } else {
        mergedHead = head2;
        head2 = head2->next;
    }

    struct Node* mergedTail = mergedHead;
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
    if (head1 != NULL) {
        mergedTail->next = head1;
    } else {
        mergedTail->next = head2;
    }

    return mergedHead;
}

int main() {
    printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
    printf("****************************\n");
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
