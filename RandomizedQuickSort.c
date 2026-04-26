#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

// Simple swap function to exchange two integers
void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

// Standard partitioning logic (Lomuto partition scheme)
int partition(int arr[], int low, int high) 
{ 
    int pivot = arr[high];   // Choose pivot as last element
    int i = (low - 1);       // Index of smaller element

    for (int j = low; j < high; j++) 
    { 
        // If current element is smaller than pivot
        if (arr[j] < pivot) 
        { 
            i++; 
            swap(&arr[i], &arr[j]); // Place smaller element before pivot
        } 
    } 
    // Place pivot in correct position
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

// Randomized QuickSort implementation
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        // Step 1: Pick a random index and swap with last element
        int randomIndex = low + rand() % (high - low + 1); 
        swap(&arr[randomIndex], &arr[high]); 

        // Step 2: Partition using the random pivot
        int pi = partition(arr, low, high); 

        // Step 3: Recursively sort left and right subarrays
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

int main() 
{ 
    int n; 
    srand(time(NULL)); // Initialize random seed

    // Input number of elements
    printf("Enter number of elements: "); 
    if (scanf("%d", &n) != 1 || n <= 0) 
    { 
        printf("Invalid input. Please enter a positive integer.\n"); 
        return 1; 
    } 

    int numbersToSort[n]; 

    // Input array elements
    printf("Enter %d integers: ", n); 
    for (int i = 0; i < n; i++) 
        scanf("%d", &numbersToSort[i]); 

    // Call randomized QuickSort
    quickSort(numbersToSort, 0, n - 1); 

    // Print sorted array
    printf("\nSorted array: "); 
    for (int i = 0; i < n; i++) 
        printf("%d ", numbersToSort[i]); 

    return 0; 
}
