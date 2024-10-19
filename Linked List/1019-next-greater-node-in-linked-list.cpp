class Solution {
public:

////////////////////////////////////////////////////////The approach is not best, the most optimal is stack for NGR////////////////////////////////////////////////

    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        ListNode* prev = head;  // Pointer to the current node we are checking
        ListNode* curr = nullptr;  // Pointer to traverse for next larger value

        // Traverse through the entire linked list
        while(prev != nullptr) {
            curr = prev->next;  // Start looking for next larger from the next node
            bool found = false;

            // Traverse the list ahead to find the next larger value
            while(curr != nullptr) {
                if(curr->val > prev->val) {
                    ans.push_back(curr->val);  // Found next larger value, store it
                    found = true;
                    break;  // Break out once we find the larger value
                }
                curr = curr->next;  // Move to the next node
            }

            // If no larger value was found, push 0
            if(!found) ans.push_back(0);

            // Move prev pointer to the next node
            prev = prev->next;
        }

        return ans;  // Return the result vector
    }
};
