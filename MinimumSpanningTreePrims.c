#include <stdio.h> 
#include <stdlib.h> 
#define V 5 // Number of vertices 

// Function to find the vertex with minimum key value (minimum edge weight)
// among the vertices not yet included in MST
int minKey(int key[], int visited[]) 
{ 
    int min = 999999; // Initialize min to a large value
    int min_index = 0; // Start with vertex 0

    for (int i = 0; i < V; i++) 
    { 
        // Pick the smallest key value among unvisited vertices
        if (!visited[i] && key[i] < min) 
        { 
            min = key[i]; 
            min_index = i; 
        } 
    } 
    return min_index; 
} 

// Function to print the constructed MST
void printPrimMST(int parent[], int graph[V][V]) 
{ 
    printf("\nPrim's MST:\n"); 
    printf("Edge \tWeight\n"); 

    int total = 0; 
    for (int i = 1; i < V; i++) 
    { 
        // parent[i] is the vertex connected to i in MST
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]); 
        total += graph[i][parent[i]]; 
    } 
    printf("Total Cost = %d\n", total); 
} 

// Prim's Algorithm Implementation
void primMST(int graph[V][V]) 
{ 
    int parent[V];  // Stores MST edges
    int key[V];     // Minimum edge weight for each vertex
    int visited[V]; // Track visited vertices

    // Step 1: Initialize all keys as infinite and visited[] as false
    for (int i = 0; i < V; i++) 
    { 
        key[i] = 999999; 
        visited[i] = 0; 
    } 

    // Step 2: Start from vertex 0
    key[0] = 0; 
    parent[0] = -1; // First node is always root of MST

    // Step 3: Construct MST with V-1 edges
    for (int count = 0; count < V - 1; count++) 
    { 
        // Pick the vertex with minimum key value not yet included in MST
        int u = minKey(key, visited); 
        visited[u] = 1; 

        // Update key and parent for adjacent vertices of u
        for (int v = 0; v < V; v++) 
        { 
            // If (u,v) is an edge, v is not visited, and weight < current key[v]
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) 
            { 
                parent[v] = u; 
                key[v] = graph[u][v]; 
            } 
        } 
    } 
    // Print the MST
    printPrimMST(parent, graph); 
} 

int main() 
{ 
    // Graph represented as adjacency matrix
    int graph[V][V] = { 
        {0, 2, 3, 0, 0}, 
        {2, 0, 5, 3, 0}, 
        {3, 5, 0, 0, 4}, 
        {0, 3, 0, 0, 2}, 
        {0, 0, 4, 2, 0}}; 

    // Run Prim's Algorithm
    primMST(graph); 
    return 0; 
}
