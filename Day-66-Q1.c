//Detect cycle in directed graph using DFS and recursion stack.
/*
Output:
- YES if cycle exists
- NO if cycle does not exist
*/
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int recStack[MAX];
int V; // number of vertices

// DFS function to detect cycle
bool dfs(int node) {
    visited[node] = 1;
    recStack[node] = 1;

    for(int i = 0; i < V; i++) {
        if(graph[node][i]) { // edge exists
            // If not visited, recurse
            if(!visited[i] && dfs(i))
                return true;

            // If already in recursion stack → cycle
            else if(recStack[i])
                return true;
        }
    }

    recStack[node] = 0; // remove from stack
    return false;
}

// Function to check cycle
bool hasCycle() {
    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            if(dfs(i))
                return true;
        }
    }
    return false;
}

int main() {
    int edges;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // initialize
    for(int i = 0; i < V; i++) {
        visited[i] = 0;
        recStack[i] = 0;
        for(int j = 0; j < V; j++)
            graph[i][j] = 0;
    }

    printf("Enter edges (u v):\n");
    for(int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; // directed edge
    }

    if(hasCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}