//WAP to generate Fibonacci Series of n-terms
#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = 0, rear = -1, size = 0;

void enqueue(int value) {
    if (size == MAX) {
        printf("Queue Overflow\n");
        return;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = value;
    size++;
}

int dequeue() {
    if (size == 0) {
        printf("Queue Underflow\n");
        return 0;
    }
    int value = queue[front];
    front = (front + 1) % MAX;
    size--;
    return value;
}

int getFront() {
    if (size == 0) {
        return 0;
    }
    return queue[front];
}

int main() {
    printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
    printf("****************************\n");
    int n, first, second, next;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 0;
    }

    printf("Fibonacci Series: ");

    if (n >= 1) {
        printf("0 ");
        enqueue(0);
    }
    if (n >= 2) {
        printf("1 ");
        enqueue(1);
    }

    for (int i = 3; i <= n; i++) {
        first = dequeue();
        second = getFront(); // front element without removing

        next = first + second;
        printf("%d ", next);

        enqueue(next);
    }

    printf("\n");
    return 0;
}
