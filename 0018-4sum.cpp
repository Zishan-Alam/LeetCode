class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;

        // Sort the array to apply the two-pointer technique
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Outer loop to fix the first number
        for (int i = 0; i < n - 3; i++) {
            // Skip duplicate values for `i`
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Second loop to fix the second number
            for (int j = i + 1; j < n - 2; j++) {
                // Skip duplicate values for `j`
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                // Two-pointer technique for the remaining two numbers
                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        // If the sum is equal to the target, add the quadruplet
                        // to the result
                        result.push_back( {nums[i], nums[j], nums[left], nums[right]} );

                        // Skip duplicate values for `left` and `right`
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        while (left < right && nums[right] == nums[right - 1])
                            right--;

                        // Move both pointers after finding a valid quadruplet
                        left++;
                        right--;
                    } else if (sum < target) {
                        // If sum is less than the target, move the left pointer
                        // to the right
                        left++;
                    } else {
                        // If sum is greater than the target, move the right
                        // pointer to the left
                        right--;
                    }
                }
            }
        }

        return result;
    }
};
