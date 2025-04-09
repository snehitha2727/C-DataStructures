#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Create a new node
struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// Display the list
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

// Delete node at specific position
void delete_at_position(struct Node** head_ref, int pos) {
    if (*head_ref == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    struct Node* temp = *head_ref;

    // Special case: delete head
    if (pos == 1) {
        *head_ref = temp->next;
        if (*head_ref != NULL) {
            (*head_ref)->prev = NULL;
        }
        free(temp);
        return;
    }

    // Traverse to the given position
    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
}

int main() {
    // Create initial list manually
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

    printf("\nDeleting the node at position 3...\n");
    delete_at_position(&head, 3);

    printf("After Deletion:\n");
    display(head);

    return 0;
}
