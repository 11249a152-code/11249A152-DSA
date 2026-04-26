#include <stdio.h> 
#define V 5   // Number of vertices
#define E 6   // Number of edges

int parent[V]; // Array to store parent (leader) of each set

// Find the representative (leader) of the set containing vertex v
int findLeader(int v) 
{ 
    while (parent[v] != v)   // Traverse up until root (self-parent)
        v = parent[v]; 
    return v; 
} 

// Merge two disjoint sets (union operation)
void mergeSets(int u, int v) 
{ 
    int a = findLeader(u); 
    int b = findLeader(v); 
    parent[a] = b; // Attach one leader to another
} 

// Bubble sort to organize edges by weight (ascending order)
void sortEdges(int edges[E][3]) 
{ 
    for (int i = 0; i < E - 1; i++) 
    { 
        for (int j = 0; j < E - i - 1; j++) 
        { 
            if (edges[j][2] > edges[j + 1][2]) // Compare weights
            { 
                for (int k = 0; k < 3; k++)    // Swap entire edge (u,v,w)
                { 
                    int temp = edges[j][k]; 
                    edges[j][k] = edges[j + 1][k]; 
                    edges[j + 1][k] = temp; 
                } 
            } 
        } 
    } 
} 

// Kruskal's Algorithm Implementation
void kruskal(int edges[E][3]) 
{ 
    sortEdges(edges); // Step 1: Sort edges by weight

    // Step 2: Initialize each vertex as its own parent (disjoint sets)
    for (int i = 0; i < V; i++) 
        parent[i] = i; 

    int count = 0, cost = 0; 
    printf("Selected Edges:\n"); 

    // Step 3: Process edges in ascending order
    for (int i = 0; i < E; i++) 
    { 
        int u = edges[i][0]; 
        int v = edges[i][1]; 
        int w = edges[i][2]; 

        // Step 4: If leaders are different, no cycle is formed
        if (findLeader(u) != findLeader(v)) 
        { 
            printf("%d -- %d (Weight: %d)\n", u, v, w); 
            mergeSets(u, v);   // Union the sets
            cost += w;         // Add edge weight to total cost
            count++;           // Increase edge count in MST
        } 

        // Stop when MST has V-1 edges
        if (count == V - 1) 
            break; 
    } 
    printf("Total Cost: %d\n", cost); 
} 

int main() 
{ 
    // Graph edges represented as {u, v, weight}
    int edges[E][3] = { 
        {0, 1, 2}, {0, 2, 3}, {1, 2, 5}, {1, 3, 3}, {2, 4, 4}, {3, 4, 2} 
    }; 

    // Run Kruskal's Algorithm
    kruskal(edges); 
    return 0; 
}
