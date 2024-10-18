class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // Three pointers to traverse the list: a (previous), b (current), c (next)
        ListNode* a = head;
        ListNode* b = head->next;
        ListNode* c = head->next->next;

        // To track the first and last critical points for maximum distance
        int firstIdx = -1;
        int lastIdx = -1;

        // To track the previous and current critical points for minimum distance
        int prevIdx = -1;
        int currIdx = -1;  
        int mini = INT_MAX;  

        int idx = 1;  // Current node index for tracking

        // Edge case: If the list has less than 3 nodes
        if (c == nullptr) return {-1, -1};

        // Traverse the list 
        while (c != nullptr) {
            // Check if node 'b' is a critical point.
            // Critical point is either a local maximum or local minimum
            if ((b->val > a->val && b->val > c->val) || (b->val < a->val && b->val < c->val)) {
                
                // For maximum distance: set first critical point, and update last critical point
                if (firstIdx == -1) firstIdx = idx;  // Set first critical point index
                else lastIdx = idx;  // Update last critical point index

                // For minimum distance: track consecutive critical points
                prevIdx = currIdx;  // Shift current to previous
                currIdx = idx;  // Set current critical point index

                // If there is a previous critical point, calculate the distance
                if (prevIdx != -1) {
                    int distance = currIdx - prevIdx;  // Distance between consecutive critical points
                    mini = min(mini, distance);  // Update minimum distance
                }
            }

            // Move all pointers to the next nodes in the list
            a = a->next;
            b = b->next;
            c = c->next;
            idx++;  // Move index forward
        }

        // Edge case: If there's no second critical point, return {-1, -1}
        if (lastIdx == -1) return {-1, -1};

        // Calculate the maximum distance between the first and last critical points
        int maxi = lastIdx - firstIdx;

        // Return both minimum and maximum distances
        return {mini, maxi};
    }
};
