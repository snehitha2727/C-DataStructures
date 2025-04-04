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

// Function to delete node at the beginning
void delete_begin(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is already empty.\n");
        return;
    }
    struct Node* temp = *head_ref;
    *head_ref = temp->next;
    free(temp);
