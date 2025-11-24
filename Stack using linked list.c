//AIM:- To perform Stack Operations using Linked List


#include <stdio.h>
#include <stdlib.h>

// Structure definition for a Linked List Node
// Each node holds an integer value and a pointer to the next node
struct Node
{
    int data;
    struct Node *next; // Pointer to the next node
};

// Function to create a new node with given data
struct Node *CreateNode(int data)
{
    // Allocating memory for the new node dynamically
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    // Checking if memory allocation was successful
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    // Assign the data and set next to NULL since it's a fresh node
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push (insert) an element onto the stack
void push(struct Node **top, int data)
{
    // Create a node for the new element
    struct Node *newElement = CreateNode(data);

    // New node's next will point to the current top
    newElement->next = *top;

    // Update top pointer to the new element
    *top = newElement;
    printf("Node with data %d pushed successfully.\n", data);
}

// Function to pop (remove) an element from the top of the stack
void pop(struct Node **top)
{
    // Underflow condition check – nothing to pop
    if (*top == NULL)
    {
        printf("Stack is empty/underflow, pop operation can't be performed.\n");
        return;
    }

    // Store the top node temporarily to free it later
    struct Node *temp = *top;

    // Move top pointer one step down
    *top = temp->next;

    // Show which element is being removed
    printf("Element %d popped from stack.\n", temp->data);

    // Free the memory of the removed node
    free(temp);
}

// Function to display all elements present in the stack
void DisplayStack(struct Node *top)
{
    // If there are no elements, just show that the stack’s empty
    if (top == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }

    // Use a temporary pointer to traverse the stack
    struct Node *temp = top;

    // Print stack elements starting from the top
    printf("\nElements In Stack: [Top] ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n"); // Indicates end of stack
}

// Main function – presents a simple menu for user interaction
int main()
{
    struct Node *top = NULL; // Initially, stack is empty
    int choice, data;

    while (1)
    {
        // Displaying the menu
        printf("\n--- Stack Using Linked List ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handling user’s choice
        switch (choice)
        {
        case 1:
            printf("Enter data to push: ");
            scanf("%d", &data);
            push(&top, data);
            break;

        case 2:
            pop(&top);
            break;

        case 3:
            DisplayStack(top);
            break;

        case 4:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}