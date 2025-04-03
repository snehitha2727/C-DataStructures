#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct SinglyLinkedList {
    struct Node* head;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() 
{

    struct SinglyLinkedList L;
    L.head = NULL;

    struct Node* n = createNode(10);
    L.head = n;

    printf("Address of head node: %p\n", (void*)L.head);
  
    printf("Data in head node: %d\n", L.head->data);

    return 0;
}
