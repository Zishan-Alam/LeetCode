class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        // Sort the array to use the two-pointer technique
        sort(nums.begin(), nums.end()); 

        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            // Skip duplicate elements for `i`
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue; // Skip the duplicate value of `i`
            }

            int j = i + 1;
            int k = n - 1;

            // Use the two-pointer technique
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0) {
                    // If the triplet sums to zero, store it in the result
                    result.push_back({nums[i], nums[j], nums[k]});

                    // Move both pointers and skip duplicates
                    while (j < k && nums[j] == nums[j + 1])
                        j++;
                    while (j < k && nums[k] == nums[k - 1])
                        k--;

                    j++;
                    k--;
                } 
                else if (sum < 0) {
                    // If sum is less than 0, move `j` right to increase the sum
                    j++;
                } 
                else {
                    // If sum is greater than 0, move `k` left to decrease the
                    // sum
                    k--;
                }
            }
        }
        return result;
    }
};
