// Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list node
struct Node {
    int data;
    struct Node* next;
};

// Stack structure
struct Stack {
    int arr[MAX];
    int top;
};

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Push into stack
void push(struct Stack* st, int x) {
    st->arr[++st->top] = x;
}

// Pop from stack
int pop(struct Stack* st) {
    return st->arr[st->top--];
}

// DFS function
void dfs(int node, int visited[], struct Stack* st, struct Node* adj[]) {
    visited[node] = 1;

    struct Node* temp = adj[node];
    while (temp != NULL) {
        if (!visited[temp->data]) {
            dfs(temp->data, visited, st, adj);
        }
        temp = temp->next;
    }

    push(st, node);
}

// Topological Sort
void topoSort(int V, struct Node* adj[]) {
    int visited[MAX] = {0};
    struct Stack st;
    st.top = -1;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, visited, &st, adj);
        }
    }

    // Print result
    while (st.top != -1) {
        printf("%d ", pop(&st));
    }
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    struct Node* adj[MAX];

    // Initialize adjacency list
    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
    }

    // Input edges
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    topoSort(V, adj);

    return 0;
}