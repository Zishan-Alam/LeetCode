class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Create a dummy node pointing to the head; useful for handling the case where head itself is removed
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Initialize prev to track the node just before the current node
        ListNode* prev = dummy;
        ListNode* curr = head;

        // Traverse through the linked list
        while(curr != nullptr) {
            
            if(curr->val == val) {
                // Skip the current node by pointing prev->next to curr->next
                prev->next = curr->next;
                // Move curr to the next node
                curr = curr->next;
            } else {
                
                prev = curr;
                // Move curr to the next node
                curr = curr->next;
            }
        }

        // Return the updated list, starting from dummy's next (which points to head or the new head if head was removed)
        return dummy->next;
    }
};
