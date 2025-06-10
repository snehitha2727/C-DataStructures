#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

// Node structure for bucket
typedef struct Node {
    float data;
    struct Node* next;
} Node;

// Insert into sorted linked list
void insert_sorted(Node** bucket, float value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    if (*bucket == NULL || (*bucket)->data >= value) {
        new_node->next = *bucket;
        *bucket = new_node;
    } else {
        Node* current = *bucket;
        while (current->next != NULL && current->next->data < value) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

// Free bucket memory
void free_buckets(Node** buckets) {
    for (int i = 0; i < BUCKET_SIZE; i++) {
        Node* current = buckets[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
}

// Bucket Sort Function
void bucket_sort(float arr[], int n) {
    Node* buckets[BUCKET_SIZE] = {NULL};

    // Put array elements in buckets
    for (int i = 0; i < n; i++) {
        int index = arr[i] * BUCKET_SIZE;  // index in bucket
        if (index >= BUCKET_SIZE) index = BUCKET_SIZE - 1;  // safety check
        insert_sorted(&buckets[index], arr[i]);
    }

    // Concatenate buckets back to array
    int idx = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        Node* current = buckets[i];
        while (current != NULL) {
            arr[idx++] = current->data;
            current = current->next;
        }
    }

    // Free memory
    free_buckets(buckets);
}

// Main to test the function
int main() {
    float arr[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    bucket_sort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    return 0;
}
