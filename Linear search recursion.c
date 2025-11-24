//AIM:- To perform linear search using recursive function

#include <stdio.h>
#include <stdbool.h>

// Recursive function to perform Linear Search in an array
int LinearSearch(int dataSet[], int size, int elementToFind, int index)
{
    // Base case: if index exceeds array size, element not found
    if (index >= size)
    {
        return -1; // Return -1 to indicate not found
    }

    // If the current element matches the element to find
    if (dataSet[index] == elementToFind)
    {
        return index; // Return the current index
    }

    // Recursive case: check next element in dataset
    return LinearSearch(dataSet, size, elementToFind, index + 1);
}

int main()
{
    int size, elementToFind, i;

    // Prompt the user to enter the dataset size
    printf("Enter the size of Data Set for Linear Search: ");
    scanf("%d", &size);

    int searchSpace[size]; // Declare array of given size

    // Input elements into the dataset
    for (i = 0; i < size; i++)
    {
        printf("Enter the %d out of %d element in data set: ", i + 1, size);
        scanf("%d", &searchSpace[i]);
    }

    // Display the entered dataset
    printf("Given Dataset for Linear Search is: ");
    for (i = 0; i < size; i++)
    {
        printf("%d - ", searchSpace[i]);
    }

    // Input the element to search for
    printf("\nEnter the element to find in the dataset: ");
    scanf("%d", &elementToFind);

    // Call the recursive LinearSearch function starting from index 0
    int foundAt = LinearSearch(searchSpace, size, elementToFind, i = 0);

    // Display the search result
    if (foundAt >= 0)
        printf("Required element %d is found in the dataset at position %d or index %d", elementToFind, foundAt + 1, foundAt);
    else
        printf("Required element %d is NOT found in the dataset!!!", elementToFind);

    return 0; // End of program
}