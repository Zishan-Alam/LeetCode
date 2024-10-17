class Solution {
public:

    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* aage = nullptr;

        while(curr != nullptr){
            aage = curr->next;
            curr->next = prev;
            prev = curr;
            curr = aage;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        //find left middle
        ListNode* slow = head;
        ListNode* fast = head;

        if(head == nullptr || head->next == nullptr) return head;

        while(fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* revList = reverse(slow->next); //aadhe part ko reverse kar rahi hai!
        slow->next = nullptr;

        ListNode* a = head;
        ListNode* b = revList;


        while(b != nullptr){
            if(a->val != b->val) return false;
            a = a->next;
            b = b->next;
        }
        return true;


    }
};
