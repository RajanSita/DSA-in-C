// WAP to implement following recursive operations on a Binary Search Tree (BST)
// a. Find an element
// b. Insert an element
// c. Delete an element
// d. Count the number
// e. Find maximum element
// f. Find minimum element
// g. Find height of the tree
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data); 
    else if (data > root->data)
        root->right = insert(root->right, data); 

    return root;
}
int find(struct Node *root, int data)
{
    if (root == NULL)
        return 0;

    if (root->data == data)
        return 1;
    else if (data < root->data)
        return find(root->left, data);
    else
        return find(root->right, data); 
}

int findMin(struct Node *root)
{
    if (root == NULL)
        return -1;

    while (root->left != NULL)
        root = root->left;

    return root->data;
}
int findMax(struct Node *root)
{
    if (root == NULL)
        return -1; 

    while (root->right != NULL)
        root = root->right;

    return root->data;
}
int countNodes(struct Node *root)
{
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right); 
}

int height(struct Node *root)
{
    if (root == NULL)
        return -1; 
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}
struct Node *deleteNode(struct Node *root, int data)
{
    if (root == NULL)
        return root;

    if (data < root->data)
    {
        root->left = deleteNode(root->left, data); 
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data); 
    }
    else
    {
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp; 
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp; 
        }
        struct Node *temp = root->right;
        while (temp && temp->left != NULL)
            temp = temp->left;

        root->data = temp->data;                         
        root->right = deleteNode(root->right, temp->data); 
    }

    return root;
}
void inorder(struct Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    printf("Rajan \t BCA 2A\n");
    printf("Enrolment No. \t 04717702024\n");
    printf("****************************\n");
    struct Node *root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");
    int element = 40;
    if (find(root, element))
        printf("Element %d found in the BST.\n", element);
    else
        printf("Element %d not found in the BST.\n", element);

    printf("Number of nodes: %d\n", countNodes(root));

    printf("Minimum element: %d\n", findMin(root));
    printf("Maximum element: %d\n", findMax(root));

    printf("Height of the tree: %d\n", height(root));

    root = deleteNode(root, 20);
    printf("Inorder Traversal after deleting 20: ");
    inorder(root);
    printf("\n");

    return 0;
}
