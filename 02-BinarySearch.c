//Binary Search
#include <stdio.h>

int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {5, 7, 23, 32, 34, 62};  // Note: The array must be sorted
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 32;
    
    int index = binarySearch(arr, 0, size - 1, target);
    
    if (index != -1)
        printf("Element %d found at index %d using Binary Search\n", target, index);
    else
        printf("Element %d not found using Binary Search\n", target);
    
    return 0;
}
