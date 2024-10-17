class Solution {
public:

    // Do sorted lists ko merge karne ka function
    ListNode* merge(ListNode* headA, ListNode* headB) {
        ListNode* temp = new ListNode(0);  // Dummy node, jo merged list ka start track karega
        ListNode* result = temp;  // Result pointer jo traverse karega

        // Jab tak dono lists mein elements hain, comparison karke merge karte hain
        while (headA != nullptr && headB != nullptr) {
            if (headA->val <= headB->val) {  
                temp->next = headA;
                headA = headA->next;
                temp = temp->next; 
            } else {  // Agar headB ki value chhoti hai
                temp->next = headB;  
                headB = headB->next;  
                temp = temp->next;  
            }
        }

        // Agar headA ya headB bacha ho toh use merged list mein add kar do
        if (headA == nullptr) temp->next = headB;
        if (headB == nullptr) temp->next = headA;

        return result->next;  // Dummy node ko skip karke actual merged list return karo
    }

    ListNode* sortList(ListNode* head) {
        // Base case: Agar list empty hai ya sirf ek element hai toh return karo
        if (head == nullptr || head->next == nullptr) return head;

        // Fast and slow pointers se middle of the list find kar rahe hain
        ListNode* slow = head;
        ListNode* fast = head;

        // Fast pointer ko 2 steps aur slow ko 1 step move karte hain to find the middle
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // Slow pointer ab list ke middle pe hai
        // List ko do parts mein divide kar rahe hain: 'a' aur 'b'
        ListNode* a = head;
        ListNode* b = slow->next;  // Second half 'b' ke liye slow->next
        slow->next = nullptr;  // First half ko end kar diya by setting slow->next to nullptr

        // Recursively dono halves ko sort karte hain
        a = sortList(a);
        b = sortList(b);

        // Dono sorted halves ko merge karte hain
        ListNode* c = merge(a, b);

        return c;  // Merged list return karte hain
    }
};
