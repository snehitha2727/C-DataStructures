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

// Insert at beginning
void insertAtBeginning(struct CircularLinkedList* list, int data) {
    struct Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        newNode->next = newNode;
    } else {
        struct Node* temp = list->head;
        while (temp->next != list->head) {
            temp = temp->next;
        }
        newNode->next = list->head;
        temp->next = newNode;
        list->head = newNode;
    }
}

// Delete at end
void deleteAtEnd(struct CircularLinkedList* list) {
    if (list->head == NULL) {
        printf("List is Empty, nothing to delete.\n");
        return;
    }

    if (list->head->next == list->head) {
        free(list->head);
        list->head = NULL;
    } else {
        struct Node* temp = list->head;
        while (temp->next->next != list->head) {
            temp = temp->next;
        }
        struct Node* lastNode = temp->next;
        temp->next = list->head;
        free(lastNode);
    }
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

    n3->next = C.head;  // Make circular

    // Display initial list
    display(&C);

    // Delete node at the end
    deleteAtEnd(&C);

    // Display updated list
    display(&C);

    return 0;
}
