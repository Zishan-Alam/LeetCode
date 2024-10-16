/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    
    ListNode* deleteDuplicates(ListNode* head) {
        // Agar list empty hai ya sirf ek node hai toh return
        if (head == nullptr || head->next == nullptr) return head;

        // Do pointers a (current) aur b (next node)
        ListNode* a = head;
        ListNode* b = head->next;

        // Jab tak b null nahi hota, list traverse karte raho
        while (b != nullptr) {
            // Jab tak a aur b ki value same hai, b ko aage badhao
            while (b != nullptr && b->val == a->val) {
                b = b->next;
            }
            // a ke next ko non-duplicate node (ya null) se link karo
            a->next = b;
            // a aur b ko ek step aage move karo
            a = b;
            if (b != nullptr) b = b->next;
        }
        // Modified linked list return karo
        return head;
    }
};
