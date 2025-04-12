//Linear
#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target)
            return i;  // Return the index if target is found
    }
    return -1;  // Return -1 if target is not found
}

int main() {
    int arr[] = {34, 7, 23, 32, 5, 62};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 23;
    
    int index = linearSearch(arr, size, target);
    
    if (index != -1)
        printf("Element %d found at index %d using Linear Search\n", target, index);
    else
        printf("Element %d not found using Linear Search\n", target);
    
    return 0;
}
