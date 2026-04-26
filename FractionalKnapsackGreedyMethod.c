#include <stdio.h> 

// Structure to represent an item with weight, value, and profit per weight ratio
struct Item 
{ 
    int weight; 
    int value; 
    float ppw; // profit per weight ratio (value/weight) 
}; 

/* 
 * Function: sort
 * Description: Sorts items by profit/weight ratio in descending order
 * Method: Bubble sort
 */
void sort(struct Item items[], int n) 
{ 
    struct Item temp; 
    for (int i = 0; i < n - 1; i++) 
    { 
        for (int j = 0; j < n - i - 1; j++) 
        { 
            // Swap if current item has lower ratio than next
            if (items[j].ppw < items[j + 1].ppw) 
            { 
                temp = items[j]; 
                items[j] = items[j + 1]; 
                items[j + 1] = temp; 
            } 
        } 
    } 
} 

int main() 
{ 
    int n; 
    float capacity; 

    // Step 1: Read number of items
    printf("Enter number of items: "); 
    scanf("%d", &n); 

    // Validate input
    if (n <= 0) 
        return 1; 

    struct Item items[n]; // Array of items

    // Step 2: Read weight and value of each item
    printf("Enter weight and value of each item:\n"); 
    for (int i = 0; i < n; i++) 
    { 
        printf("Item %d: ", i + 1); 
        scanf("%d %d", &items[i].weight, &items[i].value); 
        items[i].ppw = (float)items[i].value / items[i].weight; // Compute ratio
    } 

    // Step 3: Read knapsack capacity
    printf("Enter knapsack capacity: "); 
    scanf("%f", &capacity); 

    // Step 4: Sort items by ratio (descending)
    sort(items, n); 

    // Step 5: Greedy selection of items
    float totalProfit = 0.0; 
    for (int i = 0; i < n; i++) 
    { 
        if (capacity >= items[i].weight) 
        { 
            // Take whole item
            totalProfit += items[i].value; 
            capacity -= items[i].weight; 
        } 
        else 
        { 
            // Take fraction of item
            totalProfit += items[i].ppw * capacity; 
            break; // Knapsack is full
        } 
    } 

    // Step 6: Print maximum profit
    printf("Maximum profit = %.2f\n", totalProfit); 
    return 0; 
}
