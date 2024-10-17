class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Slow aur Fast pointers ko head se initialize kar rahe hain
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;  // Fast pointer ko do step aage badha rahe hain
            slow = slow->next;        // Slow pointer ko ek step aage badha rahe hain

            // Agar kabhi slow aur fast pointers ek hi node pe milte hain, toh cycle hai
            if(fast == slow) return true;
        }

        // Agar loop ke baad cycle detect nahi hoti, toh return false
        return false;
    }
};
