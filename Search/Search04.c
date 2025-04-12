//interpolationSearch
#include <stdio.h>

int interpolationSearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target)
                return low;
            return -1;
        }
        
        // Probing the position with keeping uniform distribution in mind.
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]));
        
        if (arr[pos] == target)
            return pos;
        if (arr[pos] < target)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

int main() {
    int arr[] = {10, 12, 16, 18, 20, 25, 30, 35, 40, 45, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 35;
    
    int index = interpolationSearch(arr, size, target);
    
    if (index != -1)
        printf("Element %d found at index %d using Interpolation Search\n", target, index);
    else
        printf("Element %d not found using Interpolation Search\n", target);
    
    return 0;
}
