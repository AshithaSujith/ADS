#include <stdio.h>
int sequentialSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Return the index of the target
        }
    }
    return -1;  
}
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
 while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; 
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; 
}

int main() {
   
    int arr1[] = {10, 20, 30, 40, 50};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int target1 = 30;

    
    int index1 = sequentialSearch(arr1, size1, target1);
    if (index1 != -1) {
        printf("Sequential Search: Element %d found at index %d.\n", target1, index1);
    } else {
        printf("Sequential Search: Element %d not found in the array.\n", target1);
    }

    
    int arr2[] = {10, 20, 30, 40, 50};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int target2 = 30;

    
    int index2 = binarySearch(arr2, size2, target2);
    if (index2 != -1) {
        printf("Binary Search: Element %d found at index %d.\n", target2, index2);
    } else {
        printf("Binary Search: Element %d not found in the array.\n", target2);
    }

    return 0;
}

