//Build a graph with n vertices and m edges using adjacency matrix representation.
/*
The graph may be directed or undirected.
Input:
- n (vertices)
- m (edges)
- m pairs (u, v)

Output:
- n x n adjacency matrix
*/
#include <stdio.h>

int main() {
    int n, m;
    
    // Input number of vertices and edges
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter number of edges: ");
    scanf("%d", &m);
    
    int adj[n][n];
    
    // Initialize matrix with 0
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
    
    int u, v;
    
    // Input edges
    printf("Enter edges (u v):\n");
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        
        adj[u][v] = 1;
        
        // For undirected graph, uncomment below line
        // adj[v][u] = 1;
    }
    
    // Print adjacency matrix
    printf("Adjacency Matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}