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
    } else {
        struct Node* temp = head;
        while (temp != NULL) {
            printf("%d --> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Function to insert a node at the end
void insert_at_ending(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    struct Node* temp = *head_ref;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
}

// Main function
int main() {
    // Create initial list manually
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

    // Display before insertion
    display(head);

    printf("\n");

    // Insert 45 at the end
    insert_at_ending(&head, 45);

    // Display after insertion
    display(head);

    // Free allocated memory
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
