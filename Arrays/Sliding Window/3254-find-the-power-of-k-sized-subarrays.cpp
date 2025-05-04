class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n) return {};  // Handle edge case where k is larger than the array size

        vector<int> result(n - k + 1, -1);
        int count = 1;

        // Pre-process the first window
        for (int i = 1; i < k; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                count++;
            } else {
                count = 1;
            }
        }

        if (count == k) {
            result[0] = nums[k - 1];
        }

        // Sliding window
        int i = 1; // Start of the result index
        int j = k; // End of the current window

        while (j < n) {
            if (nums[j] == nums[j - 1] + 1) {
                count++;
            } else {
                count = 1;
            }

            if (count >= k) {
                result[i] = nums[j];
            } else {
                result[i] = -1; // Explicitly set it to -1 if condition is not met
            }

            i++;
            j++;
        }

        return result;
    }
};





