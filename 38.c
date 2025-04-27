// Write a program to implement priority queue with three priority values (1: Lowest,2,3:Highest)
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    int priority;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *createNode(int value, int priority)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

void insert(int value, int priority)
{
    struct Node *newNode = createNode(value, priority);
    if (front == NULL || priority > front->priority)
    {
        newNode->next = front;
        front = newNode;
    }
    else
    {
        struct Node *temp = front;
        while (temp->next != NULL && temp->next->priority >= priority)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Inserted %d with priority %d\n", value, priority);
}

void delete()
{
    if (front == NULL)
    {
        printf("Priority Queue is empty\n");
        return;
    }

    struct Node *temp = front;
    printf("Deleted %d with priority %d\n", temp->data, temp->priority);
    front = front->next;
    free(temp);
}
void display()
{
    if (front == NULL)
    {
        printf("Priority Queue is empty\n");
        return;
    }

    struct Node *temp = front;
    printf("Priority Queue (Highest to Lowest):\n");
    while (temp != NULL)
    {
        printf("Data: %d, Priority: %d\n", temp->data, temp->priority);
        temp = temp->next;
    }
}

int main()
{
    printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
    printf("****************************\n");
    int choice, value, priority;
    do
    {
        printf("\n*** Priority Queue Menu ***\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            printf("Enter priority (1=Low, 2=Medium, 3=High): ");
            scanf("%d", &priority);
            if (priority >= 1 && priority <= 3)
                insert(value, priority);
            else
                printf("Invalid priority! Enter between 1 and 3.\n");
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
