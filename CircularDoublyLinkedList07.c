#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Head pointer
Node* head = NULL;

// Function to create a new node
Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->prev = new_node->next = NULL;
    return new_node;
}

// Insert node at the end
void insert_at_end(int data) {
    Node* new_node = create_node(data);

    if (head == NULL) {
        head = new_node;
        new_node->next = new_node;
        new_node->prev = new_node;
    } else {
        Node* last = head->prev;

        last->next = new_node;
        new_node->prev = last;
        new_node->next = head;
        head->prev = new_node;
    }
}

// Delete node at a given position
void delete_at_position(int position) {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    if (position < 0) {
        printf("Invalid position.\n");
        return;
    }

    Node* temp = head;
    int count = 0;

    // Deleting head node
    if (position == 0) {
        if (head->next == head) {
            free(head);
            head = NULL;
        } else {
            Node* last = head->prev;
            Node* new_head = head->next;

            last->next = new_head;
            new_head->prev = last;

            free(head);
            head = new_head;
        }
        return;
    }

    // Traverse to position
    while (count < position && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if (count == position) {
        // Deleting last node
        if (temp->next == head) {
            Node* prev_node = temp->prev;
            prev_node->next = head;
            head->prev = prev_node;
            free(temp);
        } else {  // Deleting in middle
            Node* prev_node = temp->prev;
            Node* next_node = temp->next;

            prev_node->next = next_node;
            next_node->prev = prev_node;

            free(temp);
        }
    } else {
        printf("Position exceeds the number of nodes.\n");
    }
}

// Display the circular doubly linked list
void display() {
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }

    Node* temp = head;
    do {
        printf("%d <=> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// Main function
int main() {
    // Create nodes manually like Python code
    Node* n1 = create_node(10);
    Node* n2 = create_node(20);
    Node* n3 = create_node(30);
    Node* n4 = create_node(40);
    Node* n5 = create_node(50);

    // Link nodes
    head = n1;
    n1->next = n2; n2->prev = n1;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;
    n4->next = n5; n5->prev = n4;

    // Make circular
    n5->next = head;
    head->prev = n5;

    printf("Before deleting at position:\n");
    display();

    delete_at_position(0);
    printf("After deleting at position 0:\n");
    display();

    delete_at_position(2);
    printf("After deleting at position 2:\n");
    display();

    delete_at_position(10);
    printf("After trying to delete at an invalid position:\n");
    display();

    return 0;
}
