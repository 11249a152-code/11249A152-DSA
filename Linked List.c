//AIM:- To create and perform linked list operations in DSA using C programming.

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node
{
    int data;               // Data field to store integer
    struct Node *next;      // Pointer to the next node in the list
};

// Function to create a new node and return its address
struct Node *CreateNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory
    if (!newNode) // If memory allocation fails
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;   // Assign data to node
    newNode->next = NULL;   // Initialize next pointer as NULL
    return newNode;
}

// Function to insert a node at the beginning of the list
void InsertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = CreateNode(data); // Create a new node
    newNode->next = *head;                   // Link new node to existing head
    *head = newNode;                         // Make new node the new head
    printf("Node with data %d inserted at beginning successfully.\n", data);
}

// Function to insert a node at the end of the list
void InsertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = CreateNode(data); // Create a new node

    if (*head == NULL) // If the list is empty
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head; // Temporary pointer for traversal
        while (temp->next != NULL) // Traverse till the end of list
            temp = temp->next;
        temp->next = newNode;      // Link the last node to the new node
    }

    printf("Node with data %d inserted at the end successfully.\n", data);
}

// Function to insert a node at a specific position (1-based index)
void InsertAtPosition(struct Node **head, int data, int position)
{
    if (position < 1) // Validate position
    {
        printf("Invalid position!\n");
        return;
    }

    // If position is at the beginning
    if (position == 1)
    {
        InsertAtBeginning(head, data);
        return;
    }

    struct Node *prev = *head;
    // Traverse to the (position - 1)th node
    for (int k = 1; (k < position - 1 && prev != NULL); k++)
    {
        prev = prev->next;
    }

    if (prev == NULL) // If position exceeds the current length
    {
        printf("Given position is out of range!\n");
        return;
    }

    // Create and insert node at the given position
    struct Node *newNode = CreateNode(data);
    newNode->next = prev->next;
    prev->next = newNode;

    printf("Node with data %d inserted at position %d successfully.\n", data, position);
}

// Function to delete a node by given value
void DeleteNode(struct Node **head, int valueToDelete)
{
    if (*head == NULL) // Check if list is empty
    {
        printf("Linked List is empty, deletion cannot be performed.\n");
        return;
    }

    struct Node *temp = *head;

    // Case 1: Head node contains the value
    if (temp->data == valueToDelete)
    {
        *head = temp->next;  // Move head pointer to next node
        free(temp);          // Free the deleted node
        printf("Data %d deleted from list.\n", valueToDelete);
        return;
    }

    // Case 2: Search node to be deleted, keeping track of previous node
    struct Node *prev = *head;
    while (prev->next != NULL)
    {
        if (prev->next->data == valueToDelete)
        {
            temp = prev->next;           // Node to delete
            prev->next = temp->next;     // Link bypassing the deleted node
            free(temp);                  // Free memory
            printf("Data %d deleted from list.\n", valueToDelete);
            return;
        }
        prev = prev->next;
    }

    // If element not found in list
    printf("Element %d not found.\n", valueToDelete);
}

// Function to display all elements in the linked list
void DisplayList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head; // Temporary pointer for traversal
    printf("\nLinked List Nodes: ");
    while (temp != NULL)
    {
        // Display node's address, data, and next pointer
        printf(" |At=%p|%d|Next=%p| -> ", temp, temp->data, temp->next);
        temp = temp->next;
    }
}

// Main program - provides menu-driven interface
int main()
{
    struct Node *head = NULL; // Initialize empty linked list
    int choice, data, pos;

    // Infinite loop for menu options
    while (1)
    {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete by Value\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            InsertAtBeginning(&head, data);
            break;

        case 2:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            InsertAtEnd(&head, data);
            break;

        case 3:
            printf("Enter data and position to insert: ");
            scanf("%d %d", &data, &pos);
            InsertAtPosition(&head, data, pos);
            break;

        case 4:
            printf("Enter value to delete: ");
            scanf("%d", &data);
            DeleteNode(&head, data);
            break;

        case 5:
            DisplayList(head);
            break;

        case 6:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
