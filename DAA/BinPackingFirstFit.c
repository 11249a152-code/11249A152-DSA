#include <stdio.h> 

/* 
 * Function: firstFit
 * Description: Implements the First Fit bin packing algorithm.
 * Each item is placed into the first bin that has enough remaining capacity.
 * If no bin can accommodate the item, a new bin is created.
 * @param items[]: Array of item sizes
 * @param n: Number of items
 * @param capacity: Capacity of each bin
 */
void firstFit(int items[], int n, int capacity) 
{
    int bin[n];       // Array storing remaining capacity of each bin
    int binCount = 0; // Number of bins currently in use

    // Initialize all bins with full capacity
    for (int i = 0; i < n; i++) 
        bin[i] = capacity;

    // Process each item one by one
    for (int i = 0; i < n; i++) 
    {
        int placed = 0; // Flag to check if item is placed

        // Try to fit item into existing bins
        for (int j = 0; j < binCount; j++) 
        {
            // If item fits in current bin
            if (bin[j] >= items[i]) 
            {
                bin[j] -= items[i]; // Reduce available capacity
                printf("Item %d with weight %d placed in Bin %d\n", i+1, items[i], j + 1);
                placed = 1;         // Mark item as placed
                break;              // Stop at first fit (First Fit rule)
            }
        }

        // If item did not fit in any existing bin, create a new bin
        if (!placed) 
        {
            bin[binCount] -= items[i]; 
            printf("Item %d with weight %d placed in Bin %d\n", i+1, items[i], binCount + 1);
            binCount++; 
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

    // Read bin capacity
    printf("Enter bin capacity: "); 
    scanf("%d", &capacity); 

    int items[n]; // Array to store item sizes

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

    // Call First Fit algorithm
    firstFit(items, n, capacity); 

    return 0; 
}
