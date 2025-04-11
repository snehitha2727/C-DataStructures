#include <stdio.h>
#include <stdlib.h>

// Define a node
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Define the circular doubly linked list
typedef struct {
    Node* head;
} CircularDLL;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to display the circular doubly linked list
void display(CircularDLL* list) {
    if (list->head == NULL) {
        printf("List is Empty\n");
        return;
    }
    Node* temp = list->head;
    do {
        printf("%d <=> ", temp->data);
        temp = temp->next;
    } while (temp != list->head);
    printf("(back to head)\n");
}

int main() {
    CircularDLL L;
    L.head = NULL;

    // Create nodes
    Node* n1 = createNode(10);
    Node* n2 = createNode(20);
    Node* n3 = createNode(30);
    Node* n4 = createNode(40);
    Node* n5 = createNode(50);

    // Connect nodes
    L.head = n1;
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n4;
    n4->prev = n3;
    n4->next = n5;
    n5->prev = n4;

    // Make it circular
    n5->next = L.head;
    L.head->prev = n5;

    // Display the list
    display(&L);

    return 0;
}
