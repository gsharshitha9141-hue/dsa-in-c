#include <stdio.h>
#include <stdlib.h>

// Helper function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Restores the min-heap property by moving an element down the heap
void heapifyDown(int *heap, int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest]) {
        smallest = left;
    }
    if (right < size && heap[right] < heap[smallest]) {
        smallest = right;
    }

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

// Main execution function required by LeetCode
int findKthLargest(int* nums, int numsSize, int k) {
    // Dynamically allocate memory for a min-heap of size k
    int *minHeap = (int *)malloc(k * sizeof(int));
    
    // Step 1: Fill the heap with the first k elements of the array
    for (int i = 0; i < k; i++) {
        minHeap[i] = nums[i];
    }

    // Build the initial min-heap from the bottom up
    for (int i = (k / 2) - 1; i >= 0; i--) {
        heapifyDown(minHeap, k, i);
    }

    // Step 2: Process the remaining elements in the array
    for (int i = k; i < numsSize; i++) {
        // If the current element is larger than the smallest element in our heap (the root)
        if (nums[i] > minHeap[0]) {
            minHeap[0] = nums[i];      // Replace the root
            heapifyDown(minHeap, k, 0); // Restore min-heap structure
        }
    }

    // Step 3: The root of the min-heap is now the kth largest element
    int result = minHeap[0];
    
    // Free allocated memory to prevent memory leaks
    free(minHeap);
    
    return result;
}
