class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // Slow and fast pointers initialize kiye
        ListNode* slow = head;
        ListNode* fast = head;

        // Jab tak fast pointer end tak nahi pahuchta, loop chalte rahega
        while(fast != nullptr && fast->next != nullptr) {
            // Fast pointer ko 2 steps aage badhao
            fast = fast->next->next;
            // Slow pointer ko 1 step aage badhao
            slow = slow->next;
        }

        // Jab fast pointer null ho jaye, slow pointer middle node pe hoga
        return slow;
    }
};
