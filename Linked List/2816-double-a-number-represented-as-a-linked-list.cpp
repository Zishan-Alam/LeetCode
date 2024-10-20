class Solution {
public:

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* aage = nullptr;
        
        while (curr) {
            aage = curr->next;
            curr->next = prev;
            prev = curr;
            curr = aage;
        }

        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        // List ko reverse kar rahe hain taaki units digit se start karke multiply kar sakein
        ListNode* head1 = reverse(head);
        ListNode* curr = head1;  // Reverse list ka current pointer 'curr' 

        // Dummy node jo doubled value ko store karne ke liye use hogi
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;  // 'temp' pointer dummy node ke saath move karega

        int carry = 0;

        // List ko traverse
        while (curr != nullptr) {
            int val = 2 * (curr->val) + carry;
            int digit = val % 10;  // Last digit 
            carry = val / 10;  // Naya carry 

            // Nayi node banate hain jisme doubled digit store karenge
            ListNode* newNode = new ListNode(digit);
            temp->next = newNode; 
            temp = temp->next;

            curr = curr->next;
        }

        // Agar last mein carry bacha ho to usse ek nayi node mein daal rahe hain
        if (carry > 0) {
            temp->next = new ListNode(carry);
            temp = temp->next;
        }

        // Result ko wapas reverse karte hain taaki original order mein aa jaye
        return reverse(dummy->next);
    }
};
