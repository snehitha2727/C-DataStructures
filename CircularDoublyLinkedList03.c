#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Circular Doubly Linked List structure
typedef struct {
    Node* head;
} CircularDLL;

// Function to create a new node
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->prev = new_node->next = NULL;
    return new_node;
}

// Function to display the list
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

// Function to insert at end
void insert_at_end(CircularDLL* list, int data) {
    Node* new_node = create_node(data);

    if (list->head == NULL) {
        // Empty list
        new_node->next = new_node;
        new_node->prev = new_node;
        list->head = new_node;
    } else {
        Node* last = list->head->prev;

        last->next = new_node;
        new_node->prev = last;
        new_node->next = list->head;
        list->head->prev = new_node;
    }
}

int main() {
    CircularDLL list;
    list.head = NULL;

    // Create nodes manually
    Node* n1 = create_node(10);
    Node* n2 = create_node(20);
    Node* n3 = create_node(30);
    Node* n4 = create_node(40);
    Node* n5 = create_node(50);

    list.head = n1;

    n1->next = n2; n2->prev = n1;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;
    n4->next = n5; n5->prev = n4;

    n5->next = n1; // Circular link
    n1->prev = n5;

    printf("Before inserting at end:\n");
    display(&list);

    insert_at_end(&list, 60);

    printf("After inserting at end:\n");
    display(&list);

    return 0;
}
