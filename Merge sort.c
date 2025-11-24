//AIM:- To develop and execute the Merge Sort program in DSA using C programming.


#include <stdio.h>

// Function to merge two sorted subarrays into a single sorted array
void merge(int arr[], int left, int mid, int right)
{
    int i = left;      // starting index for left subarray
    int j = mid + 1;   // starting index for right subarray
    int k = 0;         // index for temporary array

    int temp[right - left + 1];  // temporary array to hold merged elements

    // Merge both halves into temp[] until one half is completely processed
    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];   // pick element from left side
        else
            temp[k++] = arr[j++];   // pick element from right side
    }

    // Copy remaining elements from left half (if any)
    while (i <= mid)
        temp[k++] = arr[i++];

    // Copy remaining elements from right half (if any)
    while (j <= right)
        temp[k++] = arr[j++];

    // Copy sorted elements from temp[] back to original array
    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}

// Recursive Merge Sort function
// It divides the array into two halves and merges them after sorting
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;  // find middle index

        // Sort the left half
        mergeSort(arr, left, mid);

        // Sort the right half
        mergeSort(arr, mid + 1, right);

        // Merge the two sorted halves
        merge(arr, left, mid, right);
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);

    // Read array elements from user
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Call merge sort on the entire array
    mergeSort(arr, 0, n - 1);

    // Display sorted array
    printf("Sorted array (Merge Sort): ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}