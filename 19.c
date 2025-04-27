#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insert(struct Node **head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = *head;
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

int countNodes(struct Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void findMinMax(struct Node *head, int *min, int *max)
{
    if (head == NULL)
        return;

    *min = *max = head->data;
    while (head != NULL)
    {
        if (head->data < *min)
            *min = head->data;
        if (head->data > *max)
            *max = head->data;
        head = head->next;
    }
}

int main()
{
    printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
    printf("****************************\n");
    struct Node *head = NULL;
    int n, value, min, max;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        insert(&head, value);
    }

    printf("Total Nodes: %d\n", countNodes(head));

    findMinMax(head, &min, &max);
    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);

    return 0;
}
