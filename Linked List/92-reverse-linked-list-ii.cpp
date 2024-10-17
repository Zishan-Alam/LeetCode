class Solution {
public:

    ListNode* reverse(ListNode* head){
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(left == right) return head;
        //break linkedlist into three parts
        ListNode* a = nullptr;
        ListNode* b = nullptr;
        ListNode* c = nullptr;
        ListNode* d = nullptr;

        ListNode* temp = head;
        int n = 1;

        while(temp){
            if(n == left-1) a = temp;
            if(n == left) b = temp;
            if(n == right) c = temp;
            if(n == right+1) d = temp;

            temp = temp->next;
            n++;
        }
        if(a) a->next = nullptr; //edge case if left = 1 (1-1 == 0), giving nullptr exception
        c->next = nullptr;

        c = reverse(b);

        if (a) a->next = c; //edge case if left = 1
        b->next = d;

        return (a != nullptr)? head : c; //reversing the whole linkedlist, d is still at nullptr 
    }
};
