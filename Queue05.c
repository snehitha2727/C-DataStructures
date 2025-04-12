Priority Queue (Using Array)
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int priority[SIZE];
int rear = -1;

void enqueue(int value, int prio) {
    if (rear == SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }
    rear++;
    queue[rear] = value;
    priority[rear] = prio;
    printf("Inserted %d with priority %d\n", value, prio);
}

void dequeue() {
    if (rear == -1) {
        printf("Queue is empty!\n");
        return;
    }

    // Find index of element with highest priority
    int highest = 0;
    for (int i = 1; i <= rear; i++) {
        if (priority[i] > priority[highest]) {
            highest = i;
        }
    }

    // Print and remove the element with highest priority
    printf("Deleted: %d\n", queue[highest]);
    for (int i = highest; i < rear; i++) {
        queue[i] = queue[i + 1];
        priority[i] = priority[i + 1];
    }
    rear--;
}

void display() {
    if (rear == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for (int i = 0; i <= rear; i++) {
        printf("%d(Priority %d) ", queue[i], priority[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10, 3);
    enqueue(20, 1);
    enqueue(30, 2);
    display();
    dequeue();
    display();
    enqueue(40, 5);
    enqueue(50, 4);
    display();
    dequeue();
    display();
    return 0;
}
