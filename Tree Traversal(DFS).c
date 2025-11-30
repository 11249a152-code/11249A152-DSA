//AIM:- To develop and execute the Binary Search Tree(BST) traversal (Depth First Search(DFS)) program in DSA using C programming


#include <stdio.h>
#include <stdlib.h>

// Structure for each node of the binary search tree
// Each node stores an integer data value and has pointers to left and right children
struct Node
{
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node *createNode(int value)
{
    // Dynamically allocate memory for a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    // Initialize with given data and make child pointers NULL
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
// Returns the root node after inserting the new value
struct Node *insert(struct Node *root, int value)
{
    // If tree is empty, the first element becomes the root
    if (root == NULL)
    {
        return createNode(value);
    }

    // If value is smaller, insert into left subtree
    if (value < root->data)
        root->left = insert(root->left, value);

    // If value is greater, insert into right subtree
    else
        root->right = insert(root->right, value);

    return root; // Return unchanged root after insertion
}

// Preorder Traversal: Visit Root -> Left Subtree -> Right Subtree
void preorder(struct Node *root)
{
    if (root == NULL)
        return;

    // Process the root node first
    printf("%d ", root->data);

    // Then recursively traverse the left subtree
    preorder(root->left);

    // Finally, traverse the right subtree
    preorder(root->right);
}

// Inorder Traversal: Visit Left Subtree -> Root -> Right Subtree
// For a BST, this traversal prints elements in sorted order
void inorder(struct Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);        // go to left child first
    printf("%d ", root->data);  // process current node
    inorder(root->right);       // then go to right child
}

// Postorder Traversal: Visit Left Subtree -> Right Subtree -> Root
void postorder(struct Node *root)
{
    if (root == NULL)
        return;

    // Visit left child first
    postorder(root->left);

    // Then visit right child
    postorder(root->right);

    // Finally, process current node
    printf("%d ", root->data);
}

int main()
{
    int n, value;
    struct Node *root = NULL;  // start with an empty tree

    // Input number of elements to insert
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input node values one by one and insert them into the BST
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value); // insert into BST dynamically
    }

    // Display traversal results
    printf("Preorder Traversal: ");
    preorder(root);

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    return 0;
}
