//Graph Traversal: Breadth-First Search (BFS)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Define a structure for a queue
struct Queue {
    int items[MAX_VERTICES];
    int front;
    int rear;
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

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = 0;
    queue->rear = 0;
    return queue;
}

// Function to enqueue an element
void enqueue(struct Queue* queue, int value) {
    queue->items[queue->rear] = value;
    queue->rear++;
}

// Function to dequeue an element
int dequeue(struct Queue* queue) {
    int item = queue->items[queue->front];
    queue->front++;
    return item;
}

// Function to check if the queue is empty
bool isEmpty(struct Queue* queue) {
    return queue->front == queue->rear;
}

// BFS algorithm
void BFS(struct Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};  // Keep track of visited vertices
    struct Queue* queue = createQueue();
    
    visited[startVertex] = 1;
    enqueue(queue, startVertex);
    
    while (!isEmpty(queue)) {
        int vertex = dequeue(queue);
        printf("%d ", vertex);
        
        struct Node* adjList = graph->adjLists[vertex];
        struct Node* temp = adjList;
        
        while (temp != NULL) {
            int connectedVertex = temp->vertex;
            
            if (!visited[connectedVertex]) {
                visited[connectedVertex] = 1;
                enqueue(queue, connectedVertex);
            }
            
            temp = temp->next;
        }
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
    
    printf("Breadth First Search (BFS) Traversal:\n");
    BFS(graph, 0);  // Start BFS traversal from vertex 0
    
    return 0;
}
