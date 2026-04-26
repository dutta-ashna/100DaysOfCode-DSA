//Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];   // Adjacency matrix
int indegree[MAX];
int queue[MAX];

int main() {
    int V, E;
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    // Initialize adjacency matrix and indegree
    for(i = 0; i < V; i++) {
        indegree[i] = 0;
        for(j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }

    // Input edges
    printf("Enter edges (u v) meaning u -> v:\n");
    for(i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    // Queue initialization
    int front = 0, rear = 0;

    // Add all vertices with indegree 0
    for(i = 0; i < V; i++) {
        if(indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;
    int topo[MAX];

    // Kahn's Algorithm
    while(front < rear) {
        int node = queue[front++];
        topo[count++] = node;

        // Reduce indegree of adjacent nodes
        for(i = 0; i < V; i++) {
            if(adj[node][i] == 1) {
                indegree[i]--;
                if(indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    // Check for cycle
    if(count != V) {
        printf("Cycle detected! Topological sort not possible.\n");
    } else {
        printf("Topological Order: ");
        for(i = 0; i < V; i++) {
            printf("%d ", topo[i]);
        }
        printf("\n");
    }

    return 0;
}