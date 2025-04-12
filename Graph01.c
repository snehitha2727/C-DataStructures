Graph using Adjacency Matrix
#include <stdio.h>

#define MAX_VERTICES 5

// Function to add an edge in the graph
void addEdge(int graph[MAX_VERTICES][MAX_VERTICES], int src, int dest) {
    graph[src][dest] = 1;
    graph[dest][src] = 1;  // For an undirected graph
}

// Function to display the graph
void displayGraph(int graph[MAX_VERTICES][MAX_VERTICES]) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};  // Initialize graph with 0s
    
    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    
    // Display the adjacency matrix
    printf("Adjacency Matrix Representation of the Graph:\n");
    displayGraph(graph);
    
    return 0;
}
