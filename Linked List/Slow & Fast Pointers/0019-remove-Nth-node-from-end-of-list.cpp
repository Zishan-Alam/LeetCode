class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Slow aur fast pointers ko initialize kar rahe hain
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Fast pointer ko n+1 steps aage badhao
        for (int i = 1; i <= n+1; i++) {
            if (fast == nullptr) return head->next; // iska matlab head node ko delete karna hai
            fast = fast->next;  // Fast pointer ko aage badha rahe hain
        }
        
        // Dono pointers ko tab tak aage badhao jab tak fast list ke end tak nahi pahuchta
        while (fast != nullptr) {
            slow = slow->next;  // Slow pointer ek step aage
            fast = fast->next;  // Fast pointer ek step aage
        }
        
        // Ab slow->next ko remove karna hai (jo n-th node hai end se)
        slow->next = slow->next->next;  // N-th node ko skip kar rahe hain
        
        // Modified linked list ko return karo
        return head;
    }
};
