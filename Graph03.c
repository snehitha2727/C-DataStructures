//Graph Traversal: Depth-First Search (DFS)
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 5

// Define a structure for a node
struct Node {
    int vertex;
    struct Node* next;
};

// Define a structure for a graph
struct Graph {
    int numVertices;
    struct Node** adjLists;
};

// Function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with `numVertices` vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// DFS algorithm
void DFS(struct Graph* graph, int vertex, int* visited) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    struct Node* adjList = graph->adjLists[vertex];
    struct Node* temp = adjList;
    
    while (temp != NULL) {
        int connectedVertex = temp->vertex;
        
        if (!visited[connectedVertex]) {
            DFS(graph, connectedVertex, visited);
        }
        
        temp = temp->next;
    }
}

// Main function
int main() {
    struct Graph* graph = createGraph(MAX_VERTICES);
    
    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    
    printf("Depth First Search (DFS) Traversal:\n");
    
    int visited[MAX_VERTICES] = {0};  // Keep track of visited vertices
    DFS(graph, 0, visited);  // Start DFS traversal from vertex 0
    
    return 0;
}
