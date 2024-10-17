class Solution {
public:
    void deleteNode(ListNode* target) {
        //target node ki value ko uske next node ki value se replace kar diya:
        target->val = target->next->val;
        //target node ke next pointer ko next-next node se point kar diya:
        target->next = target->next->next;

        //description mai likha, it should not be a tail node, isliye uska edge case nhi ha
    }
};
