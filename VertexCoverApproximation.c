#include <stdio.h> 
#define V 5 // Number of vertices in our graph 

/* 
 * Function: findVertexCover
 * Description: Implements a simple greedy 2-approximation algorithm for Vertex Cover.
 * Strategy: For each uncovered edge (u,v), add both endpoints to the cover set.
 */
void findVertexCover(int graph[V][V]) 
{ 
    int visited[V]; // Array to represent our Cover Set 'C'

    // Step 1: Initialize all vertices as unmarked (not in cover set)
    for (int i = 0; i < V; i++) 
    { 
        visited[i] = 0; 
    } 

    // Step 2: Scan all edges in adjacency matrix
    for (int u = 0; u < V; u++) 
    { 
        for (int v = 0; v < V; v++) 
        { 
            // Condition: edge exists and both endpoints are unmarked
            if (graph[u][v] == 1 && !visited[u] && !visited[v]) 
            { 
                // Step 3: Add both endpoints to cover set
                visited[u] = 1; 
                visited[v] = 1; 

                /* Note:
                 * By marking u and v as visited, all edges incident on them
                 * are automatically considered covered. No need to explicitly delete edges.
                 */
            } 
        } 
    } 

    // Step 4: Print the cover set
    printf("Approximate Vertex Cover: "); 
    int count = 0; 
    for (int i = 0; i < V; i++) 
    { 
        if (visited[i]) 
        { 
            printf("%d ", i); 
            count++; 
        } 
    } 
    printf("\nTotal vertices in the cover: %d\n", count); 
} 

int main() 
{ 
    // Graph represented as adjacency matrix (1 = edge exists, 0 = no edge)
    int graph[V][V] = { 
        {0, 1, 0, 0, 0}, 
        {1, 0, 1, 1, 0}, 
        {0, 1, 0, 1, 1}, 
        {0, 1, 1, 0, 1}, 
        {0, 0, 1, 1, 0}}; 

    printf("Executing Vertex Cover Approximation...\n"); 
    findVertexCover(graph); 

    return 0; 
}
