/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    // Return early if the list is empty or has only one element
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    struct ListNode* current = head;
    
    // Traverse the list until the second to last node
    while (current != NULL && current->next != NULL) {
        // If the current node's value equals the next node's value, it's a duplicate
        if (current->val == current->next->val) {
            struct ListNode* temp = current->next;
            current->next = current->next->next; // Skip the duplicate node
            free(temp);                          // Free the memory of the duplicate node
        } else {
            // No duplicate, advance the pointer
            current = current->next;
        }
    }
    
    return head;
}
