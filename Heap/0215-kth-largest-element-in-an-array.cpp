// Sorting approach
// TC : O(nlogn)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n-k];
    }
};

// Heap Approach
//TC : O(nlogk)
//SC : O(k)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto &it : nums) {
            pq.push(it);

            if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};
