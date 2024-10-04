class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        // Correct formula for sum of the first n natural numbers
        int sum = n * (n + 1) / 2;

        // Calculate the sum of elements in the array
        int osum = 0;
        for (int i = 0; i < n; i++) {
            osum += nums[i];
        }

        // The missing number is the difference between expected sum and actual sum
        return sum - osum;
    }
};
