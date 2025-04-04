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

// Function to delete node at the end
void delete_end(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is already empty.\n");
        return;
    }

    struct Node* temp = *head_ref;

    // If there is only one node
    if (temp->next == NULL) {
        free(temp);
        *head_ref = NULL;
        return;
    }

    struct Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
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

    // Display before deletion
    display(head);
    printf("\n");

    // Delete from end
    delete_end(&head);

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
