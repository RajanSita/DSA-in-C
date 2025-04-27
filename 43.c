//WAP to create a Binary Search Tree (BST) and traverse the tree in Inorder, Preorder and Postorder manner using recursive functions
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
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data); 
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
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
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
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
