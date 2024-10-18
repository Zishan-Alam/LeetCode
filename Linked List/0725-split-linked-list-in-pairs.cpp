class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // Length of original linked list
        ListNode* temp = head;
        int n = 0;
        while (temp) {
            temp = temp->next;
            n++;
        }

        // Breaking the list into k parts
        vector<ListNode*> ans;
        int size = n / k;  // Basic size of each part
        int rem = n % k;   // Remainder nodes to be distributed
        temp = head;

        while (temp != nullptr) {
            ListNode* c = new ListNode(100);  // Dummy node
            ListNode* tempC = c;

            // Calculate size for this part
            int s = size + ((rem != 0) ? 1 : 0);
            rem--;

            // Loop through the current part and split it off
            for (int i = 1; i <= s && temp != nullptr; i++) {  // Add check for temp != nullptr
                tempC->next = temp;
                temp = temp->next;
                tempC = tempC->next;
            }
            tempC->next = nullptr;  // End current part
            ans.push_back(c->next);  // Add the part to the result
        }

        // If there are fewer parts than k, fill the remaining parts with nullptr
        if (ans.size() < k) {
            int extra = k - ans.size();
            for (int i = 1; i <= extra; i++) {
                ans.push_back(nullptr);
            }
        }

        return ans;
    }
};
