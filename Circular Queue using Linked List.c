//AIM:- To perform Circular Queue Operations using Linked List.


#include <stdio.h>
#include <stdlib.h>

// Node structure for circular queue using linked list
struct Node
{
    int data;
    struct Node *next;
};

// Global pointers to keep track of front and rear of the queue
struct Node *front = NULL;
struct Node *rear = NULL;

// Function to add an element to the circular queue
void enqueue(int item)
{
    // Create a new node dynamically
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    // Check if memory allocation was successful
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = item; // Assign data to the new node

    // If the queue is empty, initialize both front and rear
    if (front == NULL && rear == NULL)
    {
        front = rear = newNode;
        newNode->next = front; // Link back to front to make it circular
    }
    else // If queue already has elements
    {
        rear->next = newNode;  // Link new element after current rear
        rear = newNode;        // Move rear to point to the new node
        rear->next = front;    // Maintain circular linking
    }

    printf("%d inserted into circular queue.\n", item);
}

// Function to remove an element from the circular queue
void dequeue()
{
    // Check if queue is empty
    if (front == NULL)
    {
        printf("Queue Underflow!\n");
        return;
    }

    struct Node *temp = front; // Temporary pointer for node to be deleted

    // If there's only one node in the queue
    if (front == rear)
    {
        front = rear = NULL; // Queue becomes empty after deletion
    }
    else
    {
        front = front->next;   // Move front pointer to next node
        rear->next = front;    // Reconnect rear’s next to new front
    }

    // Display the deleted element
    printf("Deleted element: %d\n", temp->data);
    free(temp); // Free the deleted node’s memory
}

// Function to display all elements in the circular queue
void display()
{
    // If queue is empty
    if (front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    struct Node *temp = front; // Temporary pointer to traverse

    printf("Circular Queue elements: ");
    // Loop through the queue until we come back to front
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front); // Stop when we complete one full circle

    printf("\n");
}

// Main function with menu-driven approach
int main()
{
    int choice, data;

    while (1)
    {
        printf("\n--- Queue Using Linked List Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Switch case for performing chosen operation
        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            enqueue(data);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
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
