class Solution {
public:

    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* aage = nullptr;

        while(curr){
            aage = curr->next;
            curr->next = prev;
            prev = curr;
            curr = aage;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        // Agar list empty ho ya sirf ek node ho, to list ko waisa hi return karte hain
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* head1 = reverse(head);  // Reversed list ka head
        ListNode* curr = head1->next;  // Reversed list mein second node se traverse karna start karte hain

        // Dummy node create karte hain jo modified list ko track karega
        ListNode* dummy = new ListNode(0);
        dummy->next = head1;
        ListNode* temp = head1;  // 'temp' pointer jo result list ko maintain karega

        // Reversed list ko traverse karte hain
        while (curr != nullptr) {
            // Agar current node ki value temp (previous) node ki value se badi ya equal hai
            if (temp->val <= curr->val) {
                temp->next = curr;  // Temp ka next ab current node ban jata hai (current ko retain karte hain)
                temp = temp->next;
                curr = curr->next;
            } else {
                // Agar current node ki value temp node se chhoti hai, to current node ko skip karte hain
                curr = curr->next;  // Current node ko simply skip kar dete hain
            }
        }

        // Last node ka next null set karte hain taaki list ka proper end ho
        temp->next = nullptr;

        // Final list ko wapas reverse karte hain taaki original order mein aajaye
        return reverse(dummy->next);
    }
};
