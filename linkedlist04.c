#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to append a node at the end
void append(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = data;
    new_node->next = NULL;

    // If the list is empty
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    // Traverse to the end
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

// Function to display the list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is Empty\n");
    } else {
        struct Node* temp = head;
        while (temp != NULL) {
            printf("%d --> ", temp->data);
            temp = temp->next;
        }
        printf("None\n");
    }
}

// Main function
int main() {
    struct Node* head = NULL;

    // Data to be added
    int data_list[] = {10, 20, 30, 40, 50};
    int n = sizeof(data_list) / sizeof(data_list[0]);

    // Appending data iteratively
    for (int i = 0; i < n; i++) {
        append(&head, data_list[i]);
    }

    // Display the linked list
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
