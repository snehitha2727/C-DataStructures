//Heap Sort
#include <stdio.h>

void heapify(int arr[], int n, int i) {
    int largest = i;      // Initialize largest as root
    int left = 2 * i + 1;   // left child index
    int right = 2 * i + 2;  // right child index
    
    // If left child exists and is greater than root
    if (left < n && arr[left] > arr[largest])
        largest = left;
    // If right child exists and is greater than current largest
    if (right < n && arr[right] > arr[largest])
        largest = right;
    
    if (largest != i) {
        // Swap arr[i] with arr[largest]
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        
        // Heapify the affected subtree
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    // One by one extract elements from the heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        
        // Heapify the reduced heap
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original Array:\n");
    printArray(arr, n);
    
    heapSort(arr, n);
    
    printf("Sorted Array (Heap Sort):\n");
    printArray(arr, n);
    
    return 0;
}
