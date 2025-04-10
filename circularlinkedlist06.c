#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Circular Linked List structure
struct CircularLinkedList {
    struct Node* head;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Display the list
void display(struct CircularLinkedList* list) {
    if (list->head == NULL) {
        printf("List is Empty\n");
        return;
    }

    struct Node* temp = list->head;
    do {
        printf("%d --> ", temp->data);
        temp = temp->next;
    } while (temp != list->head);
    printf("(back to head)\n");
}

// Delete at a specific position
void deleteAtPosition(struct CircularLinkedList* list, int position) {
    if (list->head == NULL) {
        printf("List is Empty, nothing to delete.\n");
        return;
    }

    // Delete head node
    if (position == 0) {
        struct Node* temp = list->head;
        if (temp->next == list->head) {
            // Only one node
            free(temp);
            list->head = NULL;
        } else {
            // More than one node
            struct Node* last = list->head;
            while (last->next != list->head) {
                last = last->next;
            }
            list->head = list->head->next;
            last->next = list->head;
            free(temp);
        }
        return;
    }

    // Deleting other than head
    struct Node* current = list->head;
    struct Node* prev = NULL;
    int count = 0;

    while (count < position) {
        prev = current;
        current = current->next;
        count++;

        if (current == list->head) {
            printf("Position out of bounds.\n");
            return;
        }
    }

    prev->next = current->next;
    free(current);
}

int main() {
    struct CircularLinkedList C;
    C.head = NULL;

    // Manually create nodes
    struct Node* n = createNode(10);
    C.head = n;

    struct Node* n1 = createNode(20);
    n->next = n1;

    struct Node* n2 = createNode(30);
    n1->next = n2;

    struct Node* n3 = createNode(40);
    n2->next = n3;

    n3->next = C.head;  // Make it circular

    printf("Initial list:\n");
    display(&C);

    // Delete node at position 1
    deleteAtPosition(&C, 1);

    printf("List after deleting node at position 1:\n");
    display(&C);

    return 0;
}
