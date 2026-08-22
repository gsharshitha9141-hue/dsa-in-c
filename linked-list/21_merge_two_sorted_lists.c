/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // Create a dummy node to anchor the merged list
    struct ListNode dummy;
    struct ListNode* current = &dummy;
    dummy.next = NULL;

    // Traverse both lists until one is exhausted
    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    // Append the remaining elements of the non-empty list
    if (list1 != NULL) {
        current->next = list1;
    } else {
        current->next = list2;
    }

    // Return the head of the merged list, skipping the dummy node
    return dummy.next;
}
