//Perform BFS from a given source using queue.
/*
Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];   // Adjacency matrix
int vis[MAX];        // Visited array
int queue[MAX];      // Queue
int front = -1, rear = -1;

// Enqueue function
void enqueue(int x) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

// Dequeue function
int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

// BFS function
void BFS(int V, int s) {
    enqueue(s);
    vis[s] = 1;

    while (front <= rear) {
        int node = dequeue();
        printf("%d ", node);

        for (int i = 0; i < V; i++) {
            if (adj[node][i] == 1 && vis[i] == 0) {
                enqueue(i);
                vis[i] = 1;
            }
        }
    }
}

int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    // Initialize adjacency matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
        vis[i] = 0;
    }

    // Input edges
    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;   // Remove this line if graph is directed
    }

    int s;
    printf("Enter source vertex: ");
    scanf("%d", &s);

    printf("BFS Traversal: ");
    BFS(V, s);

    return 0;
}