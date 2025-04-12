#binarySearchExponential
#include <stdio.h>

int binarySearchExponential(int arr[], int low, int high, int target) {
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

int exponentialSearch(int arr[], int size, int target) {
    if (arr[0] == target)
        return 0;
    
    int i = 1;
    while (i < size && arr[i] <= target)
        i = i * 2;
    
    return binarySearchExponential(arr, i / 2, i < size ? i : size - 1, target);
}

int main() {
    int arr[] = {2, 4, 8, 10, 12, 14, 16, 18, 20, 24, 28, 32};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 18;
    
    int index = exponentialSearch(arr, size, target);
    
    if (index != -1)
        printf("Element %d found at index %d using Exponential Search\n", target, index);
    else
        printf("Element %d not found using Exponential Search\n", target);
    
    return 0;
}
