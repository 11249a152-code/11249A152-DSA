//AIM:- To develop and execute the Quick Sort program in DSA using C programming.


#include <stdio.h>

// Simple swap function using call by reference
// Swaps values of two variables pointed by a and b
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function — this rearranges the array around a pivot element
// All smaller elements go to the left of pivot, and larger ones go to the right
int partition(int list[], int low, int high)
{
    int pivot = list[high]; // Choose the last element as pivot
    int i = low - 1;        // Index for smaller element

    // Traverse the array and rearrange elements
    for (int j = low; j < high; j++)
    {
        // If current element is smaller than pivot
        if (list[j] < pivot)
        {
            i++; // Increment the "smaller" index
            swap(&list[i], &list[j]); // Swap current element into correct position
        }
    }

    // Finally place pivot in the correct sorted position
    swap(&list[i + 1], &list[high]);
    return i + 1; // Return the pivot index
}

// Recursive Quick Sort function
void quickSort(int list[], int low, int high)
{
    if (low < high)
    {
        // Partition the array and get the pivot index
        int pi = partition(list, low, high);

        // Recursively sort elements before and after pivot
        quickSort(list, low, pi - 1);
        quickSort(list, pi + 1, high);
    }
}

int main()
{
    int n;
    // Take total number of elements as input
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int list[n];
    printf("Enter %d elements:\n", n);

    // Read all elements from user
    for (int i = 0; i < n; i++)
        scanf("%d", &list[i]);

    // Call quickSort on the entire array
    quickSort(list, 0, n - 1);

    // Display the sorted array
    printf("Sorted array (Quick Sort): ");
    for (int i = 0; i < n; i++)
        printf("%d ", list[i]);

    return 0;
}
