class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        // Sorting the array
        sort(nums.begin(), nums.end());

        // Precompute powers of 2 up to n-1
        vector<int> pow2(n, 1);
        for (int i = 1; i < n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        int count = 0;
        int i = 0;
        int j = n - 1;

        // Two-pointer approach
        while (i <= j) {
            if (nums[i] + nums[j] <= target) {
                // All subsequences starting from i and ending at j are valid
                count = (count + pow2[j - i]) % MOD;
                i++; // Move the left pointer
            } else {
                j--; // Move the right pointer
            }
        }

        return count;
    }
};
