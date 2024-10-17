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

    void reorderList(ListNode* head) {
        //find left middle
        ListNode* slow = head;
        ListNode* fast = head;

        if(head == nullptr || head->next == nullptr) return;

        while(fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* b = reverse(slow->next); //reverse like palindrome
        ListNode* a = head;
        slow->next = nullptr;

        bool flag = true;

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while(a != nullptr && b != nullptr){ //merge like odd even linkedlist
            if(flag){
                temp->next = a;
                temp = temp->next;
                a = a->next;
                flag = !flag;
            }
            else{
                temp->next = b;
                temp = temp->next;
                b = b->next;
                flag = !flag;
            }
        }
        if(a == nullptr) temp->next = b;
        if(b == nullptr) temp->next = a;

    }
};
