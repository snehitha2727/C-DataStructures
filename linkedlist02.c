#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Node
struct Node {
    int data;
    struct Node* next;
};

// Define the structure for the Singly Linked List
struct SinglyLinkedList {
    struct Node* head;
};

int main() {
    // Create a linked list
    struct SinglyLinkedList L;
    L.head = NULL;

    // Create first node
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = 10;
    n->next = NULL;
    L.head = n;
    printf("%d\n", L.head->data);

    // Create second node and link to first
    struct Node* n1 = (struct Node*)malloc(sizeof(struct Node));
    n1->data = 20;
    n1->next = n;
    printf("%d\n", n1->data);

    // Create third node and link to second
    struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
    n2->data = 30;
    n2->next = n1;
    printf("%d\n", n2->data);

    // Create fourth node and link to third
    struct Node* n3 = (struct Node*)malloc(sizeof(struct Node));
    n3->data = 40;
    n3->next = n2;
    printf("%d\n", n3->data);

    // Free allocated memory (optional for this small example)
    free(n);
    free(n1);
    free(n2);
    free(n3);

    return 0;
}
