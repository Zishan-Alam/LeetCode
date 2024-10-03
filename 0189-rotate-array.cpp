class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // In case k is larger than the size of the array
        
        // Step 1: Reverse the entire array
        reverse(nums.begin(), nums.end());

        // Step 2: Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Step 3: Reverse the remaining elements from k to end
        reverse(nums.begin() + k, nums.end());
    }
};
