class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Slow and fast pointers ko initialize kar rahe hain
        ListNode* slow = head;
        ListNode* fast = head;

        // Agar list mein sirf ek node hai, toh usko delete karne ka matlab hai list empty ho jaye
        if (head->next == nullptr) return nullptr;

        // Traverse the list with slow and fast pointers
        // Fast pointer 2 steps aage badhta hai, slow pointer 1 step
        // Jab tak fast pointer ke aage 2 nodes hain, loop chalta rahega
        while (fast->next->next != nullptr && fast->next->next->next != nullptr) {
            fast = fast->next->next;  // Fast pointer ko do nodes aage badhao
            slow = slow->next;  // Slow pointer ko ek node aage badhao
        }

        // Slow pointer ab middle node ke ek pehle wale node pe hai
        // Slow pointer ke next ko uske next ke next node se link kar do (middle node ko skip karo)
        slow->next = slow->next->next;

        // Return the modified list
        return head;
    }
};
