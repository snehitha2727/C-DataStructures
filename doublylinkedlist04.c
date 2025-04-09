#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
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

// Insert at a specific position in the doubly linked list
void insert_at_position(struct Node** head_ref, int pos, int data) {
    struct Node* new_node = create_node(data);

    if (pos == 1) {
        new_node->next = *head_ref;
        if (*head_ref != NULL)
            (*head_ref)->prev = new_node;
        *head_ref = new_node;
        return;
    }

    struct Node* temp = *head_ref;
    for (int i = 1; i < pos - 1; i++) {
        if (temp == NULL) {
            printf("Position out of bounds\n");
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    new_node->next = temp->next;
    new_node->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = new_node;

    temp->next = new_node;
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
    // Create initial nodes
    struct Node* head = create_node(10);
    struct Node* n1 = create_node(20);
    struct Node* n2 = create_node(30);
    struct Node* n3 = create_node(40);

    // Link nodes
    head->next = n1;
    n1->prev = head;
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;

    printf("Initial Doubly Linked List:\n");
    display(head);

    // Insert node with value 12 at position 3
    printf("\nAfter Inserting 12 at Position 3:\n");
    insert_at_position(&head, 3, 12);
    display(head);

    return 0;
}
