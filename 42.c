//WAP to create a Binary tree and traverse the tree in Inorder, Preorder and Postorder manner using recursive functions
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);   
    printf("%d ", root->data); 
    inorder(root->right);    
}

void preorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data); 
    preorder(root->left);     
    preorder(root->right);  
}

void postorder(struct Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);    
    postorder(root->right);    
    printf("%d ", root->data); 
}

int main() {
    printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
    printf("****************************\n");
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
