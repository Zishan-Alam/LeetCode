class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        int res = 0;
        while(temp){
            //res = (res << 1) | temp->val;
            res = res * 2 + temp->val;
            temp = temp->next;
        }
        return res;
    }
};
