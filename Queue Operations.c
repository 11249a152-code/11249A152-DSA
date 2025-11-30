//AIM:-To perform Queue operations(Enqueue,Dequeue,Display) in DSA using C programming
#include <stdio.h>
#include <stdlib.h>

// Global variables for queue management
int front = -1, rear = -1, size;
int *QUEUE; // Pointer for dynamically allocated queue array

// Function to insert element in the queue
void enqueue(int item)
{
    // Check if queue is full
    if (rear == size - 1)
    {
        printf("Queue Overflow! Cannot insert.\n");
        return;
    }

    // If this is the first insertion
    if (front == -1)
        front = 0;

    rear++;                // Move rear pointer forward
    QUEUE[rear] = item;    // Insert new element
    printf("%d inserted into queue.\n", item);
}

// Function to delete element from the queue
void dequeue()
{
    // Check if queue is empty
    if (front == -1)
    {
        printf("Queue Underflow! Nothing to delete.\n");
        return;
    }

    int temp = QUEUE[front]; // Store dequeued element
    front++;                 // Move front pointer forward
    printf("Deleted element: %d\n", temp);

    // Reset pointers when queue becomes empty
    if (front > rear)
        front = rear = -1;
}

// Function to display all elements in the queue
void display()
{
    // Check if queue is empty
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    // Print elements from front to rear
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", QUEUE[i]);
    }
    printf("\n");
}

// Main function: menu-driven program for queue operations
int main()
{
    int choice, data;

    // Input queue size from user
    printf("Enter size of Queue: ");
    scanf("%d", &size);

    // Dynamically allocate memory for queue
    QUEUE = (int *)malloc(size * sizeof(int));
    if (QUEUE == NULL)
    {
        printf("Memory allocation failed!\n");
        return 0;
    }

    // Menu-driven interface
    while (1)
    {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform operation based on user's choice
        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            enqueue(data); // Insert element
            break;

        case 2:
            dequeue(); // Delete element
            break;

        case 3:
            display(); // Display queue content
            break;

        case 4:
            printf("Exiting...\n");
            free(QUEUE); // Free dynamically allocated memory
            exit(0);     // Terminate program

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
