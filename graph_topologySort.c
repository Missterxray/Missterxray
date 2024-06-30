#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int n;    // Number of vertices in the graph
int adj[MAX][MAX]; // Adjacency matrix
int visited[MAX];  // Array to keep track of visited nodes
int stack[MAX];    // Array to store the topological order
int top = -1;      // Stack's top

// Function to add an edge to the graph
void add_edge(int u, int v) {
    adj[u][v] = 1;
}

// Topological sorting function
void topological_sort(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            topological_sort(i);
        }
    }
    stack[++top] = v;
}

int main() {
    int u, v, edges;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter the edge (u v): ");
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }
    // Perform topological sort
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topological_sort(i);
        }
    }
    // Print topological order
    printf("Topological Order of the given graph is:\n");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}
