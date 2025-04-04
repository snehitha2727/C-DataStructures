#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to display the linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete a node at a specific position (1-based index)
void delete_at_position(struct Node** head_ref, int pos) {
    if (*head_ref == NULL || pos <= 0) {
        printf("Invalid position or empty list.\n");
        return;
    }

    struct Node* temp = *head_ref;

    // If the head is to be deleted
    if (pos == 1) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    struct Node* prev = NULL;

    for (int i = 1; temp != NULL && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }

    // If position is more than number of nodes
    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Main function
int main() {
    // Creating nodes
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n3 = (struct Node*)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = n1;

    n1->data = 20;
    n1->next = n2;

    n2->data = 30;
    n2->next = n3;

    n3->data = 40;
    n3->next = NULL;

    // Display before deletion
    display(head);
    printf("\n");

    // Delete node at position 3
    delete_at_position(&head, 3);

    // Display after deletion
    display(head);

    // Free remaining memory
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
