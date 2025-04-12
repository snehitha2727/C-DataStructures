//Selection Sort
#include <stdio.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        // Find the index of the minimum element in the unsorted portion
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        // Swap the found minimum element with the first unsorted element
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {29, 10, 14, 37, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original Array:\n");
    printArray(arr, n);
    
    selectionSort(arr, n);
    
    printf("Sorted Array (Selection Sort):\n");
    printArray(arr, n);
    
    return 0;
}
