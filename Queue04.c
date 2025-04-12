//Deque (Double-Ended Queue)
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue_front(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = front;
    if (front == NULL) {
        front = rear = newNode;
    } else {
        front->prev = newNode;
        front = newNode;
    }
    printf("Inserted %d at front\n", value);
}

void enqueue_rear(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = rear;
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Inserted %d at rear\n", value);
}

void dequeue_front() {
    if (front == NULL) {
        printf("Deque is empty!\n");
        return;
    }
    struct Node* temp = front;
    printf("Deleted %d from front\n", temp->data);
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    } else {
        front->prev = NULL;
    }
    free(temp);
}

void dequeue_rear() {
    if (rear == NULL) {
        printf("Deque is empty!\n");
        return;
    }
    struct Node* temp = rear;
    printf("Deleted %d from rear\n", temp->data);
    rear = rear->prev;
    if (rear == NULL) {
        front = NULL;
    } else {
        rear->next = NULL;
    }
    free(temp);
}

void display() {
    if (front == NULL) {
        printf("Deque is empty!\n");
        return;
    }
    struct Node* temp = front;
    printf("Deque: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    enqueue_front(10);
    enqueue_rear(20);
    enqueue_front(30);
    display();
    dequeue_front();
    display();
    enqueue_rear(40);
    display();
    dequeue_rear();
    display();
    return 0;
}
