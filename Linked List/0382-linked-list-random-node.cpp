class Solution {
public:
    vector<int> ans;
    Solution(ListNode* head) {
        ListNode* temp = head;

        while(temp){
            ans.push_back(temp->val);
            temp = temp->next;
        }
    }
    
    int getRandom() {
        int size = ans.size();

        int randomIdx = rand() % size; //{0,1,2,4,......size-1}

        return ans[randomIdx];
        
    }
};
