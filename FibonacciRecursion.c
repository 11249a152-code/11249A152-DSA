#include <stdio.h> 

/**
 * Function: fib
 * Description: Computes the nth Fibonacci term using recursion.
 * Complexity: O(2^n) due to repeated subproblems (tree recursion).
 * @param n: The index of the Fibonacci term to compute.
 * @return: The Fibonacci value at the given index.
 */
int fib(int n) 
{
    /* Base Condition:
       If n is 0 or 1, return n directly.
       F(0) = 0, F(1) = 1
    */
    if (n <= 1) 
    { 
        return n; 
    } 

    /* Recursive Step:
       F(n) = F(n-1) + F(n-2)
       Each call branches into two further calls,
       leading to exponential time complexity.
    */
    return fib(n - 1) + fib(n - 2); 
} 

int main() 
{ 
    int n, result = 0; 

    /* Step 1: Prompt user for input */
    printf("Enter the value of n: "); 
    scanf("%d", &n); 

    /* Step 2: Validate input (must be non-negative) */
    if (n < 0) 
    { 
        printf("Invalid input\n"); 
        return 1; 
    } 

    /* Step 3: Compute and display nth Fibonacci term */
    printf("\nNth Fibonacci term = %d\n", fib(n)); 

    return 0; 
}
