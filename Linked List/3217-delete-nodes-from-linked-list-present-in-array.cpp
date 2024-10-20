class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());

        //if head is present in array/set, update head
        while( head != nullptr && st.find(head->val) != st.end() ){
            head = head->next;
        }

        ListNode* curr = head;
        while(curr != nullptr && curr->next != nullptr ){

            //value is present in set, skip that value from occuring in head
            if( st.find(curr->next->val) != st.end() ) curr->next = curr->next->next;
            //value is not present, increment curr.
            else curr = curr->next;
            
        }
        return head;
        
    }
};
