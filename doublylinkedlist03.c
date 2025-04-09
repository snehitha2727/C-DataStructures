#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// Insert at the end of the doubly linked list
void insert_at_end(struct Node** head_ref, int data) {
    struct Node* new_node = create_node(data);

    if (*head_ref == NULL) {
        *head_ref = new_node;  // List is empty, set new node as head
        return;
    }

    struct Node* temp = *head_ref;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->prev = temp;
}

// Display the doubly linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <--> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Creating the doubly linked list and adding initial nodes
    struct Node* head = create_node(10);
    struct Node* n1 = create_node(20);
    struct Node* n2 = create_node(30);
    struct Node* n3 = create_node(40);

    // Linking nodes
    head->next = n1;
    n1->prev = head;
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;

    printf("Initial Doubly Linked List:\n");
    display(head);

    // Inserting a node at the end
    printf("\nAfter Inserting 45 at the End:\n");
    insert_at_end(&head, 45);
    display(head);

    return 0;
}
