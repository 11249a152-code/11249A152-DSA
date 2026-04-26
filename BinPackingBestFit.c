#include <stdio.h> 

/*
 * Function: bestFit
 * Description: Implements the Best Fit bin packing algorithm.
 * Each item is placed into the bin that will leave the least remaining space
 * after placement (i.e., the tightest fit). If no bin can accommodate the item,
 * a new bin is created.
 * @param items[]: Array of item sizes
 * @param n: Number of items
 * @param capacity: Capacity of each bin
 */
void bestFit(int items[], int n, int capacity) 
{
    printf("\nBest Fit Algorithm\n");

    int bin[n];       // Array storing remaining capacity of each bin
    int binCount = 0; // Number of bins currently in use

    // Initialize all bins with full capacity
    for (int i = 0; i < n; i++) 
        bin[i] = capacity;

    // Process each item one by one
    for (int i = 0; i < n; i++) 
    {
        int bestIndex = -1;       // Index of the best bin found
        int minSpace = capacity + 1; // Track minimum leftover space

        // Search for the bin that leaves the least space after placing the item
        for (int j = 0; j < binCount; j++) 
        {
            if (bin[j] >= items[i] && (bin[j] - items[i]) < minSpace) 
            {
                bestIndex = j;                  // Update best bin index
                minSpace = bin[j] - items[i];   // Update minimum leftover space
            }
        }

        // Place item in the best bin found
        if (bestIndex != -1) 
        {
            bin[bestIndex] -= items[i]; 
            printf("Item %d (weight: %d) placed in Bin %d\n", i + 1, items[i], bestIndex + 1);
        } 
        else // If no suitable bin found, create a new bin
        {
            bin[binCount++] -= items[i]; 
            printf("Item %d (weight: %d) placed in Bin %d\n", i + 1, items[i], binCount);
        }
    }

    // Print total number of bins used
    printf("Total bins used = %d\n", binCount); 
}

int main() 
{
    int n, capacity;

    // Read number of items
    printf("Enter number of items: "); 
    scanf("%d", &n); 

    /* Define array after knowing number of items
       - Avoids random values or wasted memory
       - Alternative: dynamic allocation or large fixed array */
    int items[n]; 

    // Read bin capacity
    printf("Enter bin capacity: "); 
    scanf("%d", &capacity); // FIXED: using %d for integer input

    // Read item sizes
    printf("Enter item sizes:\n"); 
    for (int i = 0; i < n; i++) 
    {
        int itemSize; 
        printf("Item %d: ", i + 1); 
        scanf("%d", &itemSize); 

        // Validate item size (must not exceed bin capacity)
        if (itemSize <= capacity) 
        {
            items[i] = itemSize; 
        } 
        else 
        {
            printf("Item size exceeds bin capacity. Please enter a valid size.\n"); 
            i--; // Retry input for this item
        }
    }

    // Call Best Fit algorithm
    bestFit(items, n, capacity); 

    return 0; 
}
