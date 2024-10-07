class Solution {
public:
    vector<int>& runningSum(vector<int>& nums) {
        int n = nums.size();

        // Start from the second element and accumulate the sum
        for (int i = 1; i < n; i++) {
            nums[i] = nums[i - 1] +
                      nums[i]; // Add the previous element to the current one
        }

        return nums; // Return the modified nums vector
    }
};
