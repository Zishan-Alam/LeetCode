class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return new TreeNode(head->val);

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* slow_prev = head;

        while(fast != nullptr && fast->next != nullptr){
            slow_prev = slow;
            slow = slow->next;
            fast = fast->next->next;
            
        }
        //middle node ki value se root initialize karo
        TreeNode* root = new TreeNode(slow->val);

        //breaking the linkedlist from head to slow->prev.
        slow_prev->next = nullptr;

        //recursion call to complete the tree
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};
