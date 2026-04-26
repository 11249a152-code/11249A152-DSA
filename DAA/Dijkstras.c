#include <stdio.h> 
#define V 5 
#define INF 999999 

/* 
 * Function: extractMin
 * Description: Mimics the 'Dequeue' operation by finding the vertex 
 * with the minimum distance among unvisited nodes.
 */
int extractMin(int dist[], int visited[]) 
{ 
    int min = INF, min_index = -1; 
    for (int v = 0; v < V; v++) 
    { 
        // Pick the smallest distance among unvisited vertices
        if (!visited[v] && dist[v] <= min) 
        { 
            min = dist[v]; 
            min_index = v; 
        } 
    } 
    return min_index; 
} 

/* 
 * Function: dijkstra
 * Description: Implements Dijkstra's shortest path algorithm 
 * from source vertex 0 to all other vertices.
 */
void dijkstra(int graph[V][V]) 
{ 
    int dist[V], visited[V]; // dist[] stores shortest distances, visited[] tracks processed vertices

    // Step 1: Initialize distances as INF and mark all vertices unvisited
    for (int i = 0; i < V; i++) 
    { 
        dist[i] = INF; 
        visited[i] = 0; 
    } 

    // Step 2: Distance to source vertex (0) is 0
    dist[0] = 0; 

    // Step 3: Process all vertices
    for (int count = 0; count < V; count++) 
    { 
        // Extract vertex u with minimum distance
        int u = extractMin(dist, visited); 
        if (u == -1) 
            break; 

        visited[u] = 1; // Mark u as processed

        // Step 4: Relaxation - update distances of adjacent vertices
        for (int j = 0; j < V; j++) 
        { 
            // If there is an edge (u,j) and j is unvisited
            if (graph[u][j] > 0 && !visited[j]) 
            { 
                // If new distance is shorter, update it
                if (dist[j] > dist[u] + graph[u][j]) 
                { 
                    dist[j] = dist[u] + graph[u][j]; 
                } 
            } 
        } 
    } 

    // Step 5: Print shortest distances from source
    printf("\nVertex \t Distance from Source (0)\n"); 
    for (int i = 0; i < V; i++) 
        printf("%d --> %d\n", i, dist[i]); 
} 

int main() 
{ 
    // Graph represented as adjacency matrix
    int graph[V][V] = { 
        {0, 10, 0, 30, 100}, 
        {10, 0, 50, 0, 0}, 
        {0, 50, 0, 20, 10}, 
        {30, 0, 20, 0, 60}, 
        {100, 0, 10, 60, 0}}; 

    // Run Dijkstra's Algorithm
    dijkstra(graph); 
    return 0; 
}
