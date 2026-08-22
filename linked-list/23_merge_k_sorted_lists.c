#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// Helper function to merge two sorted linked lists
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // Append the remaining nodes of whichever list is not empty
    if (list1 != NULL) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    return dummy.next;
}

// Helper function to divide and conquer the array of lists
struct ListNode* divideAndConquer(struct ListNode** lists, int start, int end) {
    if (start > end) return NULL;
    if (start == end) return lists[start];
    
    int mid = start + (end - start) / quarter; // Using bit shift or division
    mid = start + (end - start) / 2;

    struct ListNode* left = divideAndConquer(lists, start, mid);
    struct ListNode* right = divideAndConquer(lists, mid + 1, end);

    return mergeTwoLists(left, right);
}

// Main function required by LeetCode
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0 || lists == NULL) return NULL;
    return divideAndConquer(lists, 0, listsSize - 1);
}
