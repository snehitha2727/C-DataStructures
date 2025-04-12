#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Circular Linked List structure
typedef struct {
    Node* head;
} CircularLinkedList;

// Function to create a new node
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Display the circular linked list
void display(CircularLinkedList* list) {
    if (list->head == NULL) {
        printf("List is Empty\n");
        return;
    }

    Node* temp = list->head;
    do {
        printf("%d --> ", temp->data);
        temp = temp->next;
    } while (temp != list->head);
    printf("(back to head)\n");
}

// Insert node at specific position
void insert_at_position(CircularLinkedList* list, int data, int position) {
    Node* new_node = create_node(data);

    if (position == 0) {
        if (list->head == NULL) {
            new_node->next = new_node;
            list->head = new_node;
        } else {
            Node* temp = list->head;
            while (temp->next != list->head)
                temp = temp->next;

            temp->next = new_node;
            new_node->next = list->head;
            list->head = new_node;
        }
    } else {
        Node* temp = list->head;
        int count = 0;

        while (count < position - 1 && temp->next != list->head) {
            temp = temp->next;
            count++;
        }

        if (temp->next == list->head) {
            temp->next = new_node;
            new_node->next = list->head;
        } else {
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }
}

int main() {
    CircularLinkedList list;
    list.head = NULL;

    // Manually create nodes
    Node* n = create_node(10);
    Node* n1 = create_node(20);
    Node* n2 = create_node(30);
    Node* n3 = create_node(40);

    list.head = n;
    n->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = list.head;  // Make it circular

    printf("Initial Circular Linked List:\n");
    display(&list);

    insert_at_position(&list, 25, 2);  // Insert 25 at position 2
    printf("List after inserting 25 at position 2:\n");
    display(&list);

    insert_at_position(&list, 5, 0);   // Insert 5 at head
    printf("List after inserting 5 at head:\n");
    display(&list);

    insert_at_position(&list, 50, 5);  // Insert 50 at position 5 (end)
    printf("List after inserting 50 at position 5:\n");
    display(&list);

    return 0;
}
