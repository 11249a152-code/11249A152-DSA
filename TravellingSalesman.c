#include <stdio.h> 
#define MAXN 15        // Maximum number of cities
#define INF 999999     // Large value used to initialize minCost

int n; 
int d[MAXN][MAXN];     // Cost matrix: d[i][j] = cost to travel from city i to j
int dp[MAXN][1 << MAXN]; // DP table: dp[i][S] stores min cost from city i visiting set S

/*
 * Function: g(i, S)
 * Description: Returns the minimum cost of visiting all cities in set S starting from city i.
 * Parameters:
 *   i - current city
 *   S - bitmask representing set of cities left to visit
 */
int g(int i, int S) 
{
    // Base case: If no cities left in S, return cost to go back to starting city (0)
    if (S == 0) 
        return d[i][0]; 

    // If already computed, return stored value
    if (dp[i][S] != -1)  
        return dp[i][S]; 

    int minCost = INF; 

    // Try visiting each city k in S
    for (int k = 0; k < n; k++) 
    {
        // Check if city k is in set S using bitmask
        if (S & (1 << k)) 
        {
            // Recursive relation:
            // g(i, S) = d[i][k] + g(k, S without city k)
            int cost = d[i][k] + g(k, S & ~(1 << k)); 

            // Update minimum cost if better option found
            if (cost < minCost) 
            { 
                minCost = cost; 
            } 
        } 
    } 

    // Store result in DP table before returning
    return dp[i][S] = minCost; 
} 

int main() 
{
    printf("Enter number of cities: "); 
    scanf("%d", &n); 

    // Input cost matrix
    printf("Enter cost matrix:\n"); 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            scanf("%d", &d[i][j]); 

    // Initialize DP table with -1 (uncomputed)
    for (int i = 0; i < n; i++) 
        for (int mask = 0; mask < (1 << n); mask++) 
            dp[i][mask] = -1; 

    // Create initial set S containing all cities except starting city (0)
    int S = 0; 
    for (int i = 1; i < n; i++) 
        S |= (1 << i); 

    // Compute minimum cost starting from city 0 visiting all others
    int result = g(0, S); 

    // Print given cost matrix
    printf("Given Cost Matrix\n"); 
    for (int i = 0; i < n; i++) 
    { 
        printf("|"); 
        for (int j = 0; j < n; j++) 
            printf(" %d ", d[i][j]); 
        printf("|\n"); 
    } 

    // Print final minimum travelling cost
    printf("Minimum travelling cost: %d\n", result); 

    return 0; 
}
