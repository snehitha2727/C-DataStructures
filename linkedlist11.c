#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to display the list
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

// Recursive function to reverse the list
struct Node* reverse_recursive(struct Node* current, struct Node* prev) {
    if (current == NULL)
        return prev;
    struct Node* next_node = current->next;
    current->next = prev;
    return reverse_recursive(next_node, current);
}

// Main function
int main() {
    // Create nodes manually
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n3 = (struct Node*)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = n1;

    n1->data = 20;
    n1->next = n2;

    n2->data
