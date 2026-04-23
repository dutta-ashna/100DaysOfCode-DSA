//Using DFS and parent tracking, detect if undirected graph has a cycle.
/*
Output:
- YES or NO
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];

// DFS function
int dfs(int node, int parent, int adj[MAX][MAX], int n) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1) {  // edge exists
            if (!visited[i]) {
                if (dfs(i, node, adj, n))
                    return 1;
            }
            else if (i != parent) {
                return 1;  // cycle detected
            }
        }
    }
    return 0;
}

int main() {
    int n, m;
    int adj[MAX][MAX];

    // Input number of vertices and edges
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    // Input edges
    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;  // undirected graph
    }

    // Check for cycle
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, n)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}