class Solution {
public:
    // Helper function to reverse the first k nodes
    ListNode* reverse(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* aage = nullptr;

        int count = 0;
        while (curr && count < k) {
            aage = curr->next;  // Save next node
            curr->next = prev; // Reverse current node's pointer
            prev = curr;       // Move prev forward
            curr = aage;       // Move curr forward
            count++;
        }

        // Return new head after reversal
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return nullptr;

        // Step 1: Count if there are at least k nodes
        ListNode* temp = head;
        int count = 0;
        while (temp && count < k) {
            temp = temp->next;
            count++;
        }

        // If fewer than k nodes, return the head without reversal
        if (count < k) return head;

        // Step 2: Reverse the first k nodes using the reverse helper
        ListNode* newHead = reverse(head, k);

        // Step 3: Recur for the remaining nodes
        head->next = reverseKGroup(temp, k);

        // Step 4: Return the new head
        return newHead;
    }
};
