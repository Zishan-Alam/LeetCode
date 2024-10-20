class Solution {
public:

    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* aage = nullptr;

        if(head == nullptr || head->next == nullptr) return head;

        while(curr){
            aage = curr->next;
            curr->next = prev;
            prev = curr;
            curr = aage;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        //Step-01: Finding the middle node
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* mid = slow;

        //Step-02: Reversing the next part(mid to end)
        ListNode* newRev = reverse(mid);

        int result = 0;

        ListNode* temp = head;

        //Step-03: Finding the max result
        while(newRev != nullptr){
            int val = temp->val + newRev->val;
            result = max(result, val);

            newRev = newRev->next;
            temp = temp->next;
        }
        return result;
    }
};
