#include <stdlib.h>

// Helper function to merge two sorted sub-arrays
void merge(int* nums, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = 0;
    
    // Allocate temporary memory to hold the merged elements
    int total_elements = right - left + 1;
    int* temp = (int*)malloc(total_elements * sizeof(int));
    
    // Compare elements from both halves and copy the smaller one
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }
    
    // Copy any remaining elements from the left half
    while (i <= mid) {
        temp[k++] = nums[i++];
    }
    
    // Copy any remaining elements from the right half
    while (j <= right) {
        temp[k++] = nums[j++];
    }
    
    // Copy the sorted elements back into the original array
    for (i = 0; i < total_elements; i++) {
        nums[left + i] = temp[i];
    }
    
    // Free the allocated temporary buffer
    free(temp);
}

// Recursive function to divide and sort the array
void mergeSort(int* nums, int left, int right) {
    if (left >= right) {
        return;
    }
    
    int mid = left + (right - left) / 2;
    
    // Recursively sort the first and second halves
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    
    // Merge the sorted halves
    merge(nums, left, mid, right);
}

/**
 * Note: The returned array must be dynamically allocated, assumed to be passed array itself here.
 * numsSize is the size of the array.
 * returnSize is a pointer to the variable where you store the return array size.
 */
int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    
    if (numsSize <= 1) {
        return nums;
    }
    
    mergeSort(nums, 0, numsSize - 1);
    
    return nums;
}
