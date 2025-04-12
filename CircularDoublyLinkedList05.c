#include <stdio.h>
#include <stdlib.h>

// Node definition
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Head pointer
Node* head = NULL;

// Function to create a new node
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->prev = new_node->next = NULL;
    return new_node;
}

// Function to display the circular doubly linked list
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

// Function to insert at the end
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

// Function to delete at beginning
void delete_at_beginning() {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        Node* last = head->prev;
        Node* temp = head;

        head = head->next;
        head->prev = last;
        last->next = head;

        free(temp);
    }
}

int main() {
    // Manually create nodes like in the Python version
    Node* n1 = create_node(10);
    Node* n2 = create_node(20);
    Node* n3 = create_node(30);
    Node* n4 = create_node(40);
    Node* n5 = create_node(50);

    head = n1;
    n1->next = n2;
    n2->prev = n1;

    n2->next = n3;
    n3->prev = n2;

    n3->next = n4;
    n4->prev = n3;

    n4->next = n5;
    n5->prev = n4;

    n5->next = head; // circular
    head->prev = n5;

    // Display the list
    printf("Before deleting at beginning:\n");
    display();

    // Delete first node
    delete_at_beginning();
    printf("After deleting at beginning:\n");
    display();

    // Delete again
    delete_at_beginning();
    printf("After deleting again at beginning:\n");
    display();

    return 0;
}
