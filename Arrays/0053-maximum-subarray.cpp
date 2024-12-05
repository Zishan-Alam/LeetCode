class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = nums[0];  // Initialize maxSum with the first element
        int sum = nums[0];  // Initialize currentSum with the first element
        
        for (int i = 1; i < nums.size(); i++) {
            // Either add the current element to the current sum or start a new subarray from the current element
            sum = max(nums[i], sum + nums[i]);
            // Update maxSum if currentSum is larger
            maxi = max(maxi, sum);
        }
        
        return maxi;
    }
};
