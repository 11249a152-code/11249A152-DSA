#include <stdio.h> 

int main() 
{ 
    int n; 
    int a = 0, b = 1, c;   // Initialize first two Fibonacci terms (0 and 1)

    /* Prompt user to enter number of terms */
    printf("Enter the number of terms (n): "); 

    /* Input validation: must be a non-negative integer */
    if (scanf("%d", &n) != 1 || n < 0) 
    { 
        printf("Invalid input. Please enter a positive integer.\n"); 
        return 0; 
    } 

    /* Print Fibonacci series up to n terms */
    printf("Fibonacci Series: "); 

    // Handle 1st term (0)
    if (n >= 1) 
        printf("%d ", a); 

    // Handle 2nd term (1)
    if (n >= 2) 
        printf("%d ", b); 

    // Iterative computation from 3rd term onwards
    for (int i = 3; i <= n; i++) 
    { 
        c = a + b;          // Next term is sum of previous two
        printf("%d ", c);   // Print the term
        a = b;              // Update previous terms
        b = c; 
    } 

    /* Logic Fix:
       - If n == 1, the nth term is 'a' (0).
       - Otherwise, the nth term is 'b' (last computed term).
    */
    if (n == 1) 
        printf("\nFibonacci term %d = %d\n", n, a); 
    else 
        printf("\nFibonacci term %d = %d\n", n, b); 

    return 0; 
}
