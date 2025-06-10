//jump search

#include <stdio.h>
#include <math.h>

int jumpSearch(int arr[], int size, int target) {
    int step = sqrt(size);
    int prev = 0;
    
    // Finding the block where element is present
    while (arr[(step < size ? step : size) - 1] < target) {
        prev = step;
        step += sqrt(size);
        if (prev >= size)
            return -1;
    }
    
    // Linear search within the block
    for (int i = prev; i < (step < size ? step : size); i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 11;
    
    int index = jumpSearch(arr, size, target);
    
    if (index != -1)
        printf("Element %d found at index %d using Jump Search\n", target, index);
    else
        printf("Element %d not found using Jump Search\n", target);
    
    return 0;
}
