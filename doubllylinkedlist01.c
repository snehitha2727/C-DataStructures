#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Doubly Linked List structure
struct DLL {
    struct Node* head;
};

// Function to display the doubly linked list
void display(struct DLL* list) {
    if (list->head == NULL) {
        printf("List is Empty\n");
    } else {
        struct Node* temp = list->head;
        while (temp != NULL) {
            printf("%d <=> ", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    // Create DLL object
    struct DLL* L = (struct DLL*)malloc(sizeof(struct DLL));
    L->head = NULL;

    // Create nodes
    struct Node* n1 = (struct Node*)malloc(sizeof(struct Node));
    n1->data = 10;
    n1->prev = NULL;
    n1->next = NULL;
    L->head = n1;

    struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
    n2->data = 20;
    n2->prev = n1;
    n2->next = NULL;
    n1->next = n2;

    struct Node* n3 = (struct Node*)malloc(sizeof(struct Node));
    n3->data = 30;
    n3->prev = n2;
    n3->next = NULL;
    n2->next = n3;

    struct Node* n4 = (struct Node*)malloc(sizeof(struct Node));
    n4->data = 40;
    n4->prev = n3;
    n4->next = NULL;
    n3->next = n4;

    // Display the list
    display(L);
    printf("\n");

    return 0;
}
