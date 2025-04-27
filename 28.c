#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff, pow;
    struct Node* next;
} Node;

Node* createNode(int coeff, int pow) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

Node* addPolynomials(Node* p1, Node* p2) {
    Node* result = NULL, **temp = &result;
    while (p1 || p2) {
        int coeff, pow;
        if (p1 && (!p2 || p1->pow > p2->pow)) {
            coeff = p1->coeff;
            pow = p1->pow;
            p1 = p1->next;
        } else if (p2 && (!p1 || p2->pow > p1->pow)) {
            coeff = p2->coeff;
            pow = p2->pow;
            p2 = p2->next;
        } else {
            coeff = p1->coeff + p2->coeff;
            pow = p1->pow;
            p1 = p1->next;
            p2 = p2->next;
        }
        *temp = createNode(coeff, pow);
        temp = &((*temp)->next);
    }
    return result;
}

void traverse(Node* head) {
    while (head) {
        printf("%dx^%d ", head->coeff, head->pow);
        head = head->next;
        if (head) printf("+ ");
    }
    printf("\n");
}

int main() {
    printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
    printf("****************************\n");
    Node* poly1 = createNode(3, 3);
    poly1->next = createNode(2, 2);
    
    Node* poly2 = createNode(5, 3);
    poly2->next = createNode(1, 2);
    
    traverse(poly1);
    traverse(poly2);
    
    Node* sum = addPolynomials(poly1, poly2);
    traverse(sum);
    
    return 0;
}
