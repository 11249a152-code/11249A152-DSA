//AIM:- To develop and execute the Binary Search Tree(BST) level order traversal(Breadth First Search(BFS) program in DSA using C programming.


#include <stdio.h>
#include <stdlib.h>

struct Node **queue;  // Global queue pointer for level order traversal
int front = -1, rear = -1, MAX;  // Front, rear, and size for queue handling

// Structure for tree node
// Each node has data, a pointer to its left child, and a pointer to its right child
struct Node
{
    int data;
    struct Node *left, *right;
};

// Function to create a new node in the tree
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL; // Initially no children
    return newNode;
}

// Function to insert a node into the BST
// Returns the root node after insertion (used recursively)
struct Node *insert(struct Node *root, int value)
{
    // If tree is empty, create a new node
    if (root == NULL)
    {
        return createNode(value);
    }

    // Insert into left or right subtree depending on value
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root; // Return the unchanged root pointer
}

// ---------------------- Queue implementation ----------------------
// Simple queue using pointers to hold tree nodes for BFS traversal

// Function to insert a node into the queue
void enqueue(struct Node *temp)
{
    // Check if queue is full
    if (rear == MAX - 1)
        return;

    // Initialize front during first insertion
    if (front == -1)
        front = 0;

    // Insert element and move rear pointer
    queue[++rear] = temp;
}

// Function to remove and return the front element from queue
struct Node *dequeue()
{
    // Queue empty condition
    if (front == -1 || front > rear)
        return NULL;

    return queue[front++];  // Return current front and move it ahead
}

// ---------------------- Level Order Traversal ----------------------

// Function to perform level order traversal using queue
void levelOrder(struct Node *root)
{
    if (root == NULL)
        return;

    enqueue(root); // Start with root node

    // Continue until all nodes have been processed
    while (front <= rear)
    {
        // Remove one node from queue
        struct Node *current = dequeue();

        // Print the current node’s data
        printf("%d ", current->data);

        // Enqueue left and right children if they exist
        if (current->left != NULL)
            enqueue(current->left);
        if (current->right != NULL)
            enqueue(current->right);
    }
}

// -------------------------- Main Function --------------------------

int main()
{
    int value;
    struct Node *root = NULL; // Root of BST initially empty

    // Get total number of elements
    printf("Enter number of elements: ");
    scanf("%d", &MAX);

    // Dynamically allocate memory for queue
    queue = (struct Node **)malloc(MAX * sizeof(struct Node *));

    // Input values to be inserted into BST
    printf("Enter %d values:\n", MAX);
    for (int i = 0; i < MAX; i++)
    {
        scanf("%d", &value);
        root = insert(root, value); // Insert each value in BST
    }

    // Display BST in level order (BFS traversal)
    printf("\nLevel Order Traversal: ");
    levelOrder(root);

    return 0;
}
