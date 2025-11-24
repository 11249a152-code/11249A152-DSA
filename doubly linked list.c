//AIM:- To create a Doubly Linked List and carry out the required operations on it in DSA using C programming

#include <stdio.h>
#include <stdlib.h>

// Structure for a Doubly Linked List node
struct Node
{
    int data;
    struct Node *next; // pointer to next node
    struct Node *prev; // pointer to previous node
};

// Function to create a new node and return its address
struct Node *CreateNode(int data)
{
    // dynamically allocate memory for node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    // check if memory creation was successful
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    // assign data and initialize pointers as NULL
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

// insert a new node at the beginning of DLL
void InsertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = CreateNode(data);

    // point new node's next to current head
    newNode->next = *head;
    newNode->prev = NULL; // since this will be the first node

    // if list is not empty, update previous pointer of old head
    if (*head != NULL)
        (*head)->prev = newNode;

    // move head to new node
    *head = newNode;
    printf("Node with data %d inserted at beginning successfully.\n", data);
}

// insert node at end of the list
void InsertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = CreateNode(data);

    // if list is empty, new node becomes the head
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        // move to the last node
        struct Node *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;

        // adjust pointers to add node at the end
        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("Node with data %d inserted at the end successfully.\n", data);
}

// insert node at a specific position
void InsertAtPosition(struct Node **head, int data, int position)
{
    // considering position starts from 1
    if (position < 1)
    {
        printf("Invalid position!\n");
        return;
    }

    // if inserting at first position
    if (position == 1)
    {
        InsertAtBeginning(head, data);
        return;
    }

    struct Node *temp = *head;

    // traverse to (position - 1)-th node
    for (int k = 1; (k < position - 1 && temp != NULL); k++)
    {
        temp = temp->next;
    }

    // check if position is valid
    if (temp == NULL)
    {
        printf("Given position is out of range!\n");
        return;
    }

    struct Node *newNode = CreateNode(data);

    // adjusting pointers to link new node in between
    newNode->next = temp->next;
    newNode->prev = temp;

    // if not inserting at the very end
    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    printf("Node with data %d inserted at position %d successfully.\n", data, position);
}

// delete a node by a given value
void DeleteNode(struct Node **head, int valueToDelete)
{
    // if list is empty, nothing to delete
    if (*head == NULL)
    {
        printf("Linked List is empty, deletion operation can't be performed.\n");
        return;
    }

    struct Node *temp = *head;

    // case 1: head itself holds the value
    if (temp->data == valueToDelete)
    {
        *head = temp->next;

        // if list is not empty after deletion, update prev pointer of new head
        if (*head != NULL)
            (*head)->prev = NULL;

        free(temp);
        printf("Data %d deleted from list.\n", valueToDelete);
        return;
    }

    // case 2: value may be somewhere in the middle or end
    struct Node *before = *head;

    while (before->next != NULL)
    {
        // found node to be deleted
        if (before->next->data == valueToDelete)
        {
            temp = before->next;
            before->next = temp->next;

            // updating previous link if not deleting at end
            if (temp->next != NULL)
                temp->next->prev = before;

            free(temp);
            printf("Data %d deleted from list.\n", valueToDelete);
            return;
        }
        before = before->next;
    }

    // element not found
    printf("Element %d not found.\n", valueToDelete);
    return;
}

// display all nodes in the list
void DisplayList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("\nLinked List Nodes: ");
    while (temp != NULL)
    {
        // printing address links along with data
        printf(" |Prev=%p|%d|Next=%p| -> ", temp->prev, temp->data, temp->next);
        temp = temp->next;
    }
}

// main function to provide a menu-driven interface
int main()
{
    struct Node *head = NULL;
    int choice, data, pos;

    while (1)
    {
        printf("\n--- Doubly Linked List Menu ---\n");
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