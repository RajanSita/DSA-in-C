#include <stdio.h>
#include <stdlib.h>

// Structure for the tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Inorder Traversal (Left, Root, Right)
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);        // Traverse left subtree
    printf("%d ", root->data);  // Print root data
    inorder(root->right);       // Traverse right subtree
}

// Preorder Traversal (Root, Left, Right)
void preorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);  // Print root data
    preorder(root->left);       // Traverse left subtree
    preorder(root->right);      // Traverse right subtree
}

// Postorder Traversal (Left, Right, Root)
void postorder(struct Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);      // Traverse left subtree
    postorder(root->right);     // Traverse right subtree
    printf("%d ", root->data);  // Print root data
}

int main() {
    // Creating a simple binary tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Traversing the binary tree
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
